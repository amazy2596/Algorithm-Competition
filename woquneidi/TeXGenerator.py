import sys
import os
from typing import Union, Tuple, Optional, Dict, List
from pathlib import Path

from PyQt6.QtWidgets import (
    QApplication, QMainWindow, QTreeWidget, QTreeWidgetItem, QTextEdit,
    QSplitter, QVBoxLayout, QHBoxLayout, QWidget, QPushButton, QFileDialog,
    QHeaderView, QLabel, QAbstractItemView, QStyle
)
from PyQt6.QtCore import Qt, QTimer
from PyQt6.QtGui import QDragEnterEvent, QDropEvent, QIcon

# ---------------------------------------------
# 配置
# ---------------------------------------------
CODE_EXTENSIONS = {
    '.c': 'cppstyle',
    '.h': 'cppstyle',
    '.cpp': 'cppstyle',
    '.hpp': 'cppstyle',
    '.py': 'pystyle',
}
TEX_EXT = '.tex'
SECTION_COMMANDS = ["\\section", "\\subsection", "\\subsubsection", "\\subsubsubsection"]

# LaTeX 特殊字符转义表
LATEX_SPECIALS = {
    '\\': r'\textbackslash{}', '{': r'\{', '}': r'\}',
    '#': r'\#', '$': r'\$', '%': r'\%', '&': r'\&',
    '_': r'\_', '~': r'\textasciitilde{}', '^': r'\textasciicircum{}'
}

def latex_escape(s: str) -> str:
    """转义 LaTeX 特殊字符。"""
    return ''.join(LATEX_SPECIALS.get(ch, ch) for ch in s)

def latex_path(p: Union[str, Path]) -> str:
    """
    将文件路径安全地传给 LaTeX：
    - 统一为正斜杠
    - 不再做手工转义，统一用 \detokenize{...} 包裹，避免中文/@/空格等被误解析
    """
    s = str(p).replace('\\', '/')
    # 注意：这里返回的是 LaTeX 代码片段，不要再额外转义
    return r'\detokenize{' + s + '}'

def safe_relative_to(path_obj: Path, start: Path) -> str:
    """
    兼容 Python 3.8/3.9：优先尝试 relative_to，失败则用 os.path.relpath。
    返回字符串路径。
    """
    try:
        return str(path_obj.relative_to(start))
    except Exception:
        return os.path.relpath(str(path_obj), str(start))

def parse_board_author(base: str) -> Tuple[Optional[str], Optional[str]]:
    """
    解析 '板子名@作者' 形式。
    返回 (board, author)，若不匹配则 (None, None)。
    """
    if '@' in base:
        name, author = base.rsplit('@', 1)
        name = name.strip()
        author = author.strip()
        if name and author:
            return name, author
    return None, None

def split_board_author(stem: str):
    """
    把 'name@who' 的 stem 拆成 (name, who)。没有 @ 返回 (stem, None)。
    只按最后一个 @ 拆，避免名字里偶然出现的 @ 干扰。
    """
    if "@" in stem:
        name, who = stem.rsplit("@", 1)
        name = name.strip()
        who = who.strip()
        if name and who:
            return name, who
    return stem, None

# ---------------------------------------------
# 自定义 TreeWidget（限制拖放规则）
# ---------------------------------------------
class CustomTreeWidget(QTreeWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.main_window = parent  # 用来回调更新预览

    def dropEvent(self, event: QDropEvent):
        drop_item = self.itemAt(event.position().toPoint())
        drop_indicator_position = self.dropIndicatorPosition()
        dragged_items = self.selectedItems()
        if not dragged_items:
            event.ignore()
            return

        dragged_item = dragged_items[0]
        dragged_data = dragged_item.data(0, Qt.ItemDataRole.UserRole)  # None 表示目录
        drop_data = drop_item.data(0, Qt.ItemDataRole.UserRole) if drop_item else None

        # 禁止任何东西拖到“文件”里面（OnItem 且目标是文件）
        if drop_item and drop_data and drop_indicator_position == QAbstractItemView.DropIndicatorPosition.OnItem:
            event.ignore()
            return

        # 如果拖动的是目录，禁止放到文件里面
        if dragged_data is None and drop_item:
            if drop_data and drop_indicator_position == QAbstractItemView.DropIndicatorPosition.OnItem:
                event.ignore()
                return

        # 允许在不同层级间移动（只要不是 OnItem）
        super().dropEvent(event)
        self.main_window.update_preview()

# ---------------------------------------------
# 主窗口
# ---------------------------------------------
class LatexGeneratorWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("TeX Generator")
        self.setGeometry(100, 100, 1200, 800)
        self.root_dir = ""

        # 顶部栏
        top = QHBoxLayout()
        self.lbl_root = QLabel("根目录：<未选择>")
        self.lbl_root.setTextInteractionFlags(Qt.TextInteractionFlag.TextSelectableByMouse)

        btn_choose = QPushButton("选择目录")
        btn_choose.clicked.connect(self.browse_directory)

        btn_export = QPushButton("导出为 LaTeX")
        btn_export.clicked.connect(self.export_latex)

        top.addWidget(self.lbl_root, stretch=1)
        top.addWidget(btn_choose)
        top.addWidget(btn_export)

        top_widget = QWidget()
        top_widget.setLayout(top)
        top_widget.setFixedHeight(40)

        # 主分割器
        splitter = QSplitter(Qt.Orientation.Horizontal)

        # 左侧树
        self.tree = CustomTreeWidget(self)
        self.tree.setHeaderLabels(["目录 / 文件", "代码文件", "TeX文件"])
        header = self.tree.header()
        header.setStretchLastSection(False)
        header.setSectionResizeMode(0, QHeaderView.ResizeMode.Stretch)
        header.setSectionResizeMode(1, QHeaderView.ResizeMode.Fixed)
        header.setSectionResizeMode(2, QHeaderView.ResizeMode.Fixed)
        header.resizeSection(1, 100)
        header.resizeSection(2, 100)
        self.tree.setColumnCount(3)
        self.tree.setDragEnabled(True)
        self.tree.setDropIndicatorShown(True)
        self.tree.setDragDropMode(QTreeWidget.DragDropMode.InternalMove)
        self.tree.setAcceptDrops(True)

        self.tree.setStyleSheet("""
            QTreeWidget::item { padding: 2px; }
            QTreeWidget::item:selected { background-color: #4a90e2; }
        """)

        # 右侧预览
        self.preview = QTextEdit()
        self.preview.setReadOnly(True)

        splitter.addWidget(self.tree)
        splitter.addWidget(self.preview)
        splitter.setSizes([600, 600])

        # 中央布局
        central_widget = QWidget()
        main_layout = QVBoxLayout()
        main_layout.addWidget(top_widget)
        main_layout.addWidget(splitter)
        central_widget.setLayout(main_layout)
        self.setCentralWidget(central_widget)

        # 拖放
        self.setAcceptDrops(True)

        # 预览去抖
        self._preview_timer = QTimer(self)
        self._preview_timer.setSingleShot(True)
        self._preview_timer.timeout.connect(self._do_update_preview)
        self.tree.itemChanged.connect(self.update_preview)

    # ----------------- 图标后备 -----------------
    def themed_icon(self, key: str) -> QIcon:
        """
        Windows 上 QIcon.fromTheme 常为 null，这里提供标准图标后备。
        key: "folder" | "text-x-tex" | "text-x-script"
        """
        ico = QIcon.fromTheme(key)
        if not ico.isNull():
            return ico
        mapping = {
            "folder": QStyle.StandardPixmap.SP_DirIcon,
            "text-x-tex": QStyle.StandardPixmap.SP_FileIcon,
            "text-x-script": QStyle.StandardPixmap.SP_FileIcon,
        }
        return self.style().standardIcon(mapping.get(key, QStyle.StandardPixmap.SP_FileIcon))

    # ----------------- 目录选择 -----------------
    def browse_directory(self):
        directory = QFileDialog.getExistingDirectory(self, "选择目录")
        if directory:
            self.set_root_directory(directory)

    def set_root_directory(self, directory):
        self.root_dir = directory
        self._path_prefix = Path(directory).name
        self.lbl_root.setText(f"根目录：{directory}")
        # 如果 template.tex 在 root_dir 的父目录，就需要前缀（通常就是 src）
        parent = os.path.dirname(self.root_dir)
        self._path_prefix = os.path.basename(self.root_dir) if os.path.exists(os.path.join(parent, "template.tex")) else ""
        self.load_directory_structure()

    # ----------------- 拖入目录 -----------------
    def dragEnterEvent(self, event: QDragEnterEvent):
        if event.mimeData().hasUrls():
            event.acceptProposedAction()

    def dropEvent(self, event: QDropEvent):
        urls = event.mimeData().urls()
        if urls and urls[0].isLocalFile():
            path = urls[0].toLocalFile()
            if os.path.isdir(path):
                self.set_root_directory(path)
                event.acceptProposedAction()

    # ----------------- 加载目录树 -----------------
    def load_directory_structure(self):
        self.tree.clear()
        if not self.root_dir:
            return

        root = Path(self.root_dir)

        items: List[QTreeWidgetItem] = []
        for entry in sorted(root.iterdir(), key=lambda e: e.name):
            if entry.is_dir():
                dir_item = QTreeWidgetItem(self.tree, [entry.name])
                dir_item.setIcon(0, self.themed_icon("folder"))
                self._populate_tree(entry, dir_item)
                if dir_item.childCount() > 0:
                    items.append(dir_item)
            else:
                base, ext = os.path.splitext(entry.name)
                if ext.lower() in CODE_EXTENSIONS:
                    tex_path = entry.with_suffix(TEX_EXT)
                    has_tex = tex_path.exists()
                    board, author = parse_board_author(base)
                    item = QTreeWidgetItem(self.tree, [entry.name])
                    item.setIcon(0, self.themed_icon("text-x-script"))
                    item.setData(0, Qt.ItemDataRole.UserRole, {
                        'type': 'code',
                        'path': str(entry),
                        'base': base,
                        'ext': ext,
                        'has_tex': has_tex,
                        'board': board,
                        'author': author
                    })
                    item.setFlags(item.flags() | Qt.ItemFlag.ItemIsUserCheckable | Qt.ItemFlag.ItemIsDragEnabled | Qt.ItemFlag.ItemIsDropEnabled | Qt.ItemFlag.ItemIsEnabled | Qt.ItemFlag.ItemIsSelectable)
                    item.setCheckState(1, Qt.CheckState.Checked)
                    item.setCheckState(2, Qt.CheckState.Checked if has_tex else Qt.CheckState.Unchecked)
                    items.append(item)
                elif ext.lower() == TEX_EXT:
                    # 只收集“孤立的 .tex（无对应代码文件）”
                    code_found = False
                    for code_ext in CODE_EXTENSIONS:
                        if (root / f"{base}{code_ext}").exists():
                            code_found = True
                            break
                    if not code_found:
                        item = QTreeWidgetItem(self.tree, [entry.name])
                        item.setIcon(0, self.themed_icon("text-x-tex"))
                        item.setData(0, Qt.ItemDataRole.UserRole, {
                            'type': 'tex',
                            'path': str(entry),
                            'base': base
                        })
                        item.setFlags(item.flags() | Qt.ItemFlag.ItemIsUserCheckable | Qt.ItemFlag.ItemIsDragEnabled | Qt.ItemFlag.ItemIsDropEnabled | Qt.ItemFlag.ItemIsEnabled | Qt.ItemFlag.ItemIsSelectable)
                        item.setText(1, "")
                        item.setCheckState(2, Qt.CheckState.Checked)
                        items.append(item)

        for item in items:
            self.tree.addTopLevelItem(item)

        self.update_preview()

    def _populate_tree(self, path: Path, parent_item: QTreeWidgetItem):
        items: List[QTreeWidgetItem] = []
        for entry in sorted(path.iterdir(), key=lambda e: e.name):
            if entry.is_dir():
                dir_item = QTreeWidgetItem(parent_item, [entry.name])
                dir_item.setIcon(0, self.themed_icon("folder"))
                self._populate_tree(entry, dir_item)
                if dir_item.childCount() > 0:
                    items.append(dir_item)
            else:
                base, ext = os.path.splitext(entry.name)
                if ext.lower() in CODE_EXTENSIONS:
                    tex_path = entry.with_suffix(TEX_EXT)
                    has_tex = tex_path.exists()
                    board, author = parse_board_author(base)
                    item = QTreeWidgetItem(parent_item, [entry.name])
                    item.setIcon(0, self.themed_icon("text-x-script"))
                    item.setData(0, Qt.ItemDataRole.UserRole, {
                        'type': 'code',
                        'path': str(entry),
                        'base': base,
                        'ext': ext,
                        'has_tex': has_tex,
                        'board': board,
                        'author': author
                    })
                    item.setFlags(item.flags() | Qt.ItemFlag.ItemIsUserCheckable | Qt.ItemFlag.ItemIsDragEnabled | Qt.ItemFlag.ItemIsDropEnabled | Qt.ItemFlag.ItemIsEnabled | Qt.ItemFlag.ItemIsSelectable)
                    item.setCheckState(1, Qt.CheckState.Checked)
                    item.setCheckState(2, Qt.CheckState.Checked if has_tex else Qt.CheckState.Unchecked)
                    items.append(item)
                elif ext.lower() == TEX_EXT:
                    # 只收集“孤立的 .tex（无对应代码文件）”
                    code_found = False
                    for code_ext in CODE_EXTENSIONS:
                        if (entry.with_suffix(code_ext)).exists():
                            code_found = True
                            break
                    if not code_found:
                        item = QTreeWidgetItem(parent_item, [entry.name])
                        item.setIcon(0, self.themed_icon("text-x-tex"))
                        item.setData(0, Qt.ItemDataRole.UserRole, {
                            'type': 'tex',
                            'path': str(entry),
                            'base': base
                        })
                        item.setFlags(item.flags() | Qt.ItemFlag.ItemIsUserCheckable | Qt.ItemFlag.ItemIsDragEnabled | Qt.ItemFlag.ItemIsDropEnabled | Qt.ItemFlag.ItemIsEnabled | Qt.ItemFlag.ItemIsSelectable)
                        item.setText(1, "")
                        item.setCheckState(2, Qt.CheckState.Checked)
                        items.append(item)

        for item in items:
            parent_item.addChild(item)

    # ----------------- 预览（去抖） -----------------
    def update_preview(self):
        self._preview_timer.start(80)  # 80ms 去抖

    def _do_update_preview(self):
        scrollbar = self.preview.verticalScrollBar()
        pos = scrollbar.value()   # 保存当前位置
        latex = self.generate_latex()
        self.preview.setPlainText(latex)
        # 延迟恢复滚动条位置，避免跳到顶部
        QTimer.singleShot(0, lambda: scrollbar.setValue(pos))

    # ----------------- 导出 -----------------
    def export_latex(self):
        if not self.root_dir:
            return
        file_path, _ = QFileDialog.getSaveFileName(self, "导出 LaTeX 文件", "", "LaTeX 文件 (*.tex)")
        if file_path:
            with open(file_path, 'w', encoding='utf-8') as f:
                f.write(self.generate_latex())

    # ----------------- 生成 LaTeX -----------------
    def generate_latex(self) -> str:
        if self.tree.topLevelItemCount() == 0:
            return ""
        lines: List[str] = []
        for i in range(self.tree.topLevelItemCount()):
            self._generate_latex_recursive(self.tree.topLevelItem(i), 0, lines, "")
        return "\n".join(lines)

    def _insert_code_listing_for_item(self, item: QTreeWidgetItem, depth: int, lines: List[str], root: Path, with_prefix):
        """
        为“单个文件的小节”插入内容：先同名 .tex（若勾选且存在），再代码清单。
        注意：作者已放到标题里，不再单独插作者行。
        """
        data = item.data(0, Qt.ItemDataRole.UserRole)
        if not data or data['type'] != 'code':
            return

        # 同名 .tex
        if item.checkState(2) == Qt.CheckState.Checked and data.get('has_tex'):
            tex_file = Path(data['path']).with_suffix(TEX_EXT)
            rel_tex = with_prefix(safe_relative_to(tex_file, root))
            if tex_file.exists():
                lines.append(f"\\input{{{latex_path(rel_tex)}}}")
            else:
                lines.append(f"% MISSING TEX: {rel_tex}")

        # 代码
        if item.checkState(1) == Qt.CheckState.Checked:
            code_file = Path(data['path'])
            rel_code = with_prefix(safe_relative_to(code_file, root))
            style = CODE_EXTENSIONS.get(data['ext'].lower(), 'codestyle')
            if code_file.exists():
                lines.append(f"\\lstinputlisting[style={style}]{{{latex_path(rel_code)}}}")
            else:
                lines.append(f"% MISSING CODE: {rel_code}")

    def _generate_latex_recursive(self, item: QTreeWidgetItem, depth: int, lines: List[str], current_path: str):
        data = item.data(0, Qt.ItemDataRole.UserRole)
        root = Path(self.root_dir)

        # 路径前缀
        prefix = getattr(self, "_path_prefix", None) or Path(self.root_dir).name
        def with_prefix(p) -> Path:
            p = Path(p)
            return Path(prefix) / p if prefix else p

        # 根据层级选择我们在 .tex 里定义的命令名
        def heading_cmd(has_author: bool) -> str:
            if depth == 0:
                return r"\SecWithAuthor" if has_author else r"\section"
            elif depth == 1:
                return r"\SubsecWithAuthor" if has_author else r"\subsection"
            else:
                return r"\SubsubsecWithAuthor" if has_author else r"\subsubsection"

        if data:
            base = data['base']
            name, author = split_board_author(base)  # '板子@作者'
            title_main = latex_escape(name.replace('_', ' '))

            if data['type'] == 'code':
                show_section = (
                    (item.checkState(2) == Qt.CheckState.Checked and data['has_tex']) or
                    item.checkState(1) == Qt.CheckState.Checked
                )
                if show_section:
                    if author:
                        # 用我们定义的命令：正文里有大号作者徽标；目录里作者右对齐
                        lines.append(f"{heading_cmd(True)}{{{title_main}}}{{{latex_escape(author)}}}")
                    else:
                        # 没作者就普通标题
                        lines.append(f"{heading_cmd(False)}{{{title_main}}}")

                # —— 插入同名 .tex
                if item.checkState(2) == Qt.CheckState.Checked and data.get('has_tex'):
                    tex_file = Path(data['path']).with_suffix(TEX_EXT)
                    rel_tex = with_prefix(safe_relative_to(tex_file, root))
                    lines.append(f"\\input{{{latex_path(rel_tex)}}}")

                # —— 插入代码文件
                if item.checkState(1) == Qt.CheckState.Checked:
                    code_file = Path(data['path'])
                    rel_code = with_prefix(safe_relative_to(code_file, root))
                    style = CODE_EXTENSIONS.get(data['ext'].lower(), 'codestyle')
                    lines.append(f"\\lstinputlisting[style={style}]{{{latex_path(rel_code)}}}")

            elif data['type'] == 'tex':
                if item.checkState(2) == Qt.CheckState.Checked:
                    if author:
                        lines.append(f"{heading_cmd(True)}{{{title_main}}}{{{latex_escape(author)}}}")
                    else:
                        lines.append(f"{heading_cmd(False)}{{{title_main}}}")
                    tex_file = Path(data['path'])
                    rel_tex = with_prefix(safe_relative_to(tex_file, root))
                    lines.append(f"\\input{{{latex_path(rel_tex)}}}")

        else:
            # 目录节点
            if item.childCount() == 0:
                return
            dir_name = latex_escape(item.text(0))
            # 目录节点一般没有作者，直接按层级输出普通标题
            if depth == 0:
                lines.append(f"\\section{{{dir_name}}}")
            elif depth == 1:
                lines.append(f"\\subsection{{{dir_name}}}")
            else:
                lines.append(f"\\subsubsection{{{dir_name}}}")

            child_path = os.path.join(current_path, item.text(0)).replace('\\', '/')
            for i in range(item.childCount()):
                self._generate_latex_recursive(item.child(i), depth + 1, lines, child_path)

# ---------------------------------------------
# 入口
# ---------------------------------------------
if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = LatexGeneratorWindow()
    window.show()
    sys.exit(app.exec())
