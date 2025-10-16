import os
import shutil

# ==============================================================================
# ACM Template Reorganization Script (Python Version)
# ==============================================================================
#
# 功能: 自动整理 ACM_template/src 文件夹，创建新的子目录结构并移动文件。
# 使用: 将此脚本放置在 src 文件夹的父目录中，然后通过 `python organize_template.py` 运行。
#
# ==============================================================================

# 设置脚本的基础路径为 src 文件夹
BASE_PATH = "src"

def move_item_safely(source, destination):
    """一个安全的移动函数，在移动前检查源是否存在"""
    try:
        if os.path.exists(source):
            shutil.move(source, destination)
            print(f"  - 已移动: {source} -> {destination}")
        else:
            print(f"  - 警告: 源不存在, 跳过: {source}")
    except Exception as e:
        print(f"  - 错误: 移动 {source} 时发生错误: {e}")

def main():
    """脚本主函数"""
    print("开始整理 ACM 模板库...")
    if not os.path.isdir(BASE_PATH):
        print(f"错误: 目标根目录 '{BASE_PATH}' 不存在。请确保脚本与 'src' 文件夹在同一目录下。")
        return

    print(f"目标根目录: {os.path.abspath(BASE_PATH)}")

    # --- 步骤 1: 创建所有需要的新目录结构 ---
    print("\n[1/4] 正在创建新的目录结构...")
    new_dirs = [
        # 数据结构
        "数据结构/并查集", "数据结构/线段树", "数据结构/树状数组",
        "数据结构/平衡树", "数据结构/ST表", "数据结构/其他",
        # 数学
        "数学/数论", "数学/组合数学", "数学/线性代数", "数学/多项式",
        # 图论
        "图论/网络流", "图论/树上算法", "图论/树上算法/LCA", "图论/树上算法/树链剖分",
        # 字符串
        "字符串/KMP与AC自动机", "字符串/字典树(Trie)", "字符串/回文串", "字符串/字符串哈希"
    ]
    for rel_path in new_dirs:
        dir_path = os.path.join(BASE_PATH, rel_path)
        if not os.path.exists(dir_path):
            os.makedirs(dir_path)
            print(f"  - 已创建: {dir_path}")

    # --- 步骤 2: 移动单个文件 ---
    print("\n[2/4] 正在移动文件...")
    file_moves = {
        # 数据结构
        "数据结构/并查集@amazy.cpp": "数据结构/并查集/",
        "数据结构/并查集@woquneidi.cpp": "数据结构/并查集/",
        "数据结构/DSU@Song4u.cpp": "数据结构/并查集/",
        "数据结构/珂朵莉@amazy.cpp": "数据结构/其他/",
        "数据结构/区间修改线段树@woquneidi.cpp": "数据结构/线段树/",
        "数据结构/树状数组(单点修改 + 区间查询 + 第k小值)@amazy.cpp": "数据结构/树状数组/",
        "数据结构/树状数组(区间修改 + 查询)@amazy.cpp": "数据结构/树状数组/",
        "数据结构/树状数组@woquneidi.cpp": "数据结构/树状数组/",
        "数据结构/线段树(未修改)(SegmentTree+Info 初始赋值+单点修改+查找前驱后继)@woquneidi.cpp": "数据结构/线段树/",
        "数据结构/线段树(SegmentTree+Info 初始赋值+单点修改+查找前驱后继)@woquneidi.cpp": "数据结构/线段树/",
        "数据结构/线段树@amazy.cpp": "数据结构/线段树/",
        "数据结构/ST表@amazy.cpp": "数据结构/ST表/",
        "数据结构/ST表@woquneidi.cpp": "数据结构/ST表/",
        "数据结构/treap@amazy.cpp": "数据结构/平衡树/",
        # 数学
        "数学/二次剩余@amazy.cpp": "数学/数论/",
        "数学/扩展gcd@woquneidi.cpp": "数学/数论/",
        "数学/线性筛@amazy.cpp": "数学/数论/",
        "数学/组合数@amazy.cpp": "数学/组合数学/",
        "数学/组合数@woquneidi.cpp": "数学/组合数学/",
        "数学/组合数学公式.tex": "数学/组合数学/",
        "数学/矩阵快速幂@amazy.cpp": "数学/线性代数/",
        "数学/线性基@amazy.cpp": "数学/线性代数/",
        "数学/FFT@amazy.cpp": "数学/多项式/",
        "数学/FWT@amazy.cpp": "数学/多项式/",
        "数学/MTT@amazy.cpp": "数学/多项式/",
        "数学/NTT@amazy.cpp": "数学/多项式/",
        # 图论
        "图论/dinic求最大流@woquneidi.cpp": "图论/网络流/",
        "图论/最大流最小费用@woquneidi.cpp": "图论/网络流/",
        # 字符串
        "字符串/扩展kmp@amazy.cpp": "字符串/KMP与AC自动机/",
        "字符串/ac自动机@amazy.cpp": "字符串/KMP与AC自动机/",
        "字符串/KMP@woquneidi.cpp": "字符串/KMP与AC自动机/",
        "字符串/01字典树@amazy.cpp": "字符串/字典树(Trie)/",
        "字符串/字典树@amazy.cpp": "字符串/字典树(Trie)/",
        "字符串/字典树@woquneidi.cpp": "字符串/字典树(Trie)/",
        "字符串/trie@woquneidi.cpp": "字符串/字典树(Trie)/",
        "字符串/回文自动机@amazy.cpp": "字符串/回文串/",
        "字符串/马拉车@amazy.cpp": "字符串/回文串/",
        "字符串/字符串哈希@amazy.cpp": "字符串/字符串哈希/",
        "字符串/hash_string@woquneidi.cpp": "字符串/字符串哈希/",
    }
    for src, dst in file_moves.items():
        move_item_safely(os.path.join(BASE_PATH, src), os.path.join(BASE_PATH, dst))

    # --- 步骤 3: 移动整个文件夹的内容 ---
    print("\n[3/4] 正在移动文件夹内容...")
    dir_content_moves = {
        "图论/LCA": "图论/树上算法/LCA/",
        "图论/树链剖分": "图论/树上算法/树链剖分/"
    }
    for src_rel, dst_rel in dir_content_moves.items():
        src_full = os.path.join(BASE_PATH, src_rel)
        dst_full = os.path.join(BASE_PATH, dst_rel)
        if os.path.isdir(src_full):
            for filename in os.listdir(src_full):
                move_item_safely(os.path.join(src_full, filename), dst_full)
    
    # 重命名带全角括号的文件夹
    old_tarjan_path = os.path.join(BASE_PATH, "图论", "连通性（tarjan）")
    new_tarjan_path = os.path.join(BASE_PATH, "图论", "连通性(Tarjan)")
    if os.path.exists(old_tarjan_path):
        os.rename(old_tarjan_path, new_tarjan_path)
        print(f"  - 已重命名: {old_tarjan_path} -> {new_tarjan_path}")


    # --- 步骤 4: 清理旧的空目录 ---
    print("\n[4/4] 正在清理空的旧目录...")
    old_dirs_to_remove = [
        "图论/LCA",
        "图论/树链剖分"
    ]
    for rel_path in old_dirs_to_remove:
        dir_path = os.path.join(BASE_PATH, rel_path)
        if os.path.isdir(dir_path) and not os.listdir(dir_path):
            os.rmdir(dir_path)
            print(f"  - 已删除空目录: {dir_path}")

    print("\n模板库整理完成！")

if __name__ == "__main__":
    main()