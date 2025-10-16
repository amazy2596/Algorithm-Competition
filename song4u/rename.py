#!/usr/bin/env python3
# rename_add_author.py
# 递归遍历目录，把 *.cpp 改名为  原名@作者.cpp
# 选项：--force 覆盖已有作者；--update-tex 连带改同名 .tex；--dry-run 试运行；
#      --on-conflict {skip,overwrite,inc} 处理同名冲突；--ext 设定扩展名，默认 .cpp

import argparse
import os
from pathlib import Path
from typing import Tuple

def parse_args():
    p = argparse.ArgumentParser(description="递归给代码文件批量加上 @作者 后缀")
    p.add_argument("root", type=Path, help="要遍历的根目录")
    p.add_argument("-a", "--author", required=True, help="作者字符串，例如 amazy")
    p.add_argument("--ext", default=".cpp", help="目标扩展名（默认 .cpp）")
    p.add_argument("--force", action="store_true", help="已带 @作者 也强制替换为指定作者")
    p.add_argument("--update-tex", action="store_true", help="同时重命名同名 .tex（保持与代码基名一致）")
    p.add_argument("--dry-run", action="store_true", help="试运行，只打印不改名")
    p.add_argument("--on-conflict", choices=["skip", "overwrite", "inc"], default="skip",
                   help="目标文件已存在时的策略：skip=跳过（默认），overwrite=覆盖，inc=加数字后缀")
    return p.parse_args()

def split_board_author(stem: str) -> Tuple[str, str | None]:
    """
    把 'name@who' 的 stem 拆成 (name, who)；没有 @ 则返回 (stem, None)
    仅按最后一个 @ 拆分，避免名字里偶然出现的 @ 干扰。
    """
    if "@" in stem:
        name, who = stem.rsplit("@", 1)
        name = name.strip()
        who = who.strip()
        if name and who:
            return name, who
    return stem, None

def resolve_conflict(path: Path, strategy: str) -> Path | None:
    if not path.exists():
        return path
    if strategy == "skip":
        return None
    if strategy == "overwrite":
        return path
    # "inc": 增加 -1, -2, ...
    base = path.stem
    suf = path.suffix
    parent = path.parent
    k = 1
    while True:
        cand = parent / f"{base}-{k}{suf}"
        if not cand.exists():
            return cand
        k += 1

def maybe_rename(src: Path, dst: Path, dry_run: bool, conflict: str) -> Path | None:
    target = resolve_conflict(dst, conflict)
    if target is None:
        print(f"[SKIP] 目标已存在且策略=skip：{dst}")
        return None
    if dry_run:
        print(f"[DRY]  {src}  ->  {target}")
        return target
    if target.exists() and conflict == "overwrite":
        try:
            target.unlink()
        except Exception as e:
            print(f"[ERR] 无法删除已存在目标：{target} ({e})")
            return None
    try:
        src.rename(target)
        print(f"[OK ]  {src}  ->  {target}")
        return target
    except Exception as e:
        print(f"[ERR] 重命名失败：{src} -> {target} ({e})")
        return None

def main():
    args = parse_args()
    root: Path = args.root.resolve()
    ext = args.ext if args.ext.startswith(".") else "." + args.ext
    author = args.author

    if not root.exists() or not root.is_dir():
        print(f"[ERR] 根目录不存在或不是目录：{root}")
        return

    total = 0
    changed = 0

    for p in root.rglob(f"*{ext}"):
        if not p.is_file():
            continue
        total += 1

        stem_old = p.stem
        name, who = split_board_author(stem_old)

        # 决定新 stem
        if who:
            if args.force:
                stem_new = f"{name}@{author}"
            else:
                # 已有作者且不强制 -> 跳过
                # 但如果作者不同且你想统一，可加 --force
                print(f"[KEEP] 已含作者（{who}），未指定 --force：{p}")
                continue
        else:
            stem_new = f"{name}@{author}"

        if stem_new == stem_old:
            print(f"[KEEP] 无需改名：{p}")
            continue

        dst = p.with_name(stem_new + p.suffix)
        res = maybe_rename(p, dst, args.dry_run, args.on_conflict)
        if res is None:
            continue
        changed += 1

    print(f"\n完成：扫描 {total} 个 {ext}，改名 {changed} 个。")

if __name__ == "__main__":
    main()
