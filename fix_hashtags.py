import re
import sys


def process_vhd(filename):
    try:
        with open(filename, "r", encoding="utf-8") as f:
            lines = f.readlines()
    except Exception:
        with open(filename, "r", encoding="latin-1") as f:
            lines = f.readlines()

    new_lines = []
    counter = 0

    for line in lines:
        if re.search(r'X"[0-9A-Fa-f_]+"', line):
            if "--" in line:
                code_part, comment_part = line.split("--", 1)
            else:
                code_part = line.rstrip()
                comment_part = ""

            clean_comment = re.sub(r"#.*$", "", comment_part).strip()

            if not clean_comment and not comment_part:
                clean_comment = "instruction"

            hex_val = f"{counter:02X}"
            new_tag = f"#{counter:02d} ({hex_val})"

            new_line = f"{code_part.ljust(15)}-- {clean_comment} {new_tag}\n"
            counter += 1
            new_lines.append(new_line)
        else:
            new_lines.append(line)

    with open(filename, "w", encoding="utf-8") as f:
        f.writelines(new_lines)

    print(f"Готово! Обработано команд: {counter}")


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Использование: python fix_hashtags.py <путь_к_файлу>")
    else:
        process_vhd(sys.argv[1])
