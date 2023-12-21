#!/bin/bash

# RPN 프로그램의 실행 파일 이름
RPN_PROGRAM="./RPN"

# 테스트 케이스 배열
TEST_CASES=(
    "1 2 +"
    "4 5 *"
    "6 7 -"
    "8 3 /"
    "2 3 4 + +"
    "5 6 7 * +"
    "0 9 +"
    "1 2 * 3 +"
    "2 3 4 * +"
    "6 2 / 3 -"
    "1 2 + 3 4 + *"
    "2 3 4 * 5 + +"
    "7 8 * 9 +"
    "3 4 + 5 6 * -"
    "1 2 + 3 * 4 -"
    "0 1 2 + +"
    "9 8 - 7 6 - *"
    "2 2 + 2 2 + *"
    "3 3 * 3 /"
    "4 4 4 + +"
)

# 예상 결과 배열
EXPECTED_RESULTS=(
    "3"
    "20"
    "-1"
    "2"
    "9"
    "47"
    "9"
    "5"
    "14"
    "0"
    "21"
    "19"
    "65"
    "-23"
    "5"
    "3"
    "1"
    "16"
    "3"
    "12"
)

# 테스트 케이스 수 확인
NUM_TESTS=${#TEST_CASES[@]}

# 각 테스트 케이스를 순회하면서 RPN 프로그램 실행
for (( i=0; i<$NUM_TESTS; i++ )); do
    TEST=${TEST_CASES[$i]}
    EXPECTED=${EXPECTED_RESULTS[$i]}

    echo "RPN Input: '$TEST'"
    OUTPUT=$($RPN_PROGRAM "$TEST")
    echo "Output: $OUTPUT"
    echo "Expected Result: $EXPECTED"
    
    # 결과 비교
    if [ "$OUTPUT" == "$EXPECTED" ]; then
        echo "Test Passed"
    else
        echo "Test Failed"
    fi
    echo "-------------------"
done
