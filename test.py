import glob
import re

# 재귀적으로 모든 하위 디렉토리의 Makefile 탐색 및 처리
for filename in glob.iglob('**/*.mk', recursive=True):
    with open(filename, 'r', encoding='utf-8') as file:
        content = file.readlines()

    # 주석 및 빈 줄 제거
    non_empty_lines = []
    in_comment_block = True
    for line in content:
        # 파일 시작 부분의 주석 또는 빈 줄이 아닌 내용이 나타나면 처리 종료
        if not in_comment_block or (line.strip() and not line.strip().startswith('#')):
            in_comment_block = False
        if in_comment_block and (line.strip().startswith('#') or not line.strip()):
            continue  # 주석 라인 또는 빈 줄 스킵
        non_empty_lines.append(line)

    updated_content = ''.join(non_empty_lines)

    with open(filename, 'w', encoding='utf-8') as file:
        file.write(updated_content)

print("모든 Makefile에서 시작 부분의 주석 및 빈 줄이 제거되었습니다.")
