#!/bin/bash

# Colors for output
GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m" # No color

# Function to run test cases
test_push_swap() {
    local input="$1"
    local expected_output="$2"
    local output
    
    output=$(./push_swap $input 2>&1)
    
    if [[ "$output" == "$expected_output" ]]; then
        echo -e "${GREEN}PASS${NC}: ./push_swap $input"
    else
        echo -e "${RED}FAIL${NC}: ./push_swap $input"
        echo -e "    Expected: '$expected_output'"
        echo -e "    Got:      '$output'"
    fi
}

# Valid cases
test_push_swap "3 4 6 8 9 74 -56 +495" ""
test_push_swap "2147483647 843 56544 24394" ""

# Error cases
test_push_swap "1 3 dog 35 80 -3" "Error"
test_push_swap "a" "Error"
test_push_swap "1 2 3 5 67b778 947" "Error"
test_push_swap "12 4 6 8 54fhd 4354" "Error"
test_push_swap "1 -- 45 32" "Error"
test_push_swap "1 3 58 9 3" "Error"
test_push_swap "3 03" "Error"
test_push_swap "49 128 50 38 49" "Error"
test_push_swap "54867543867438 3" "Error"
test_push_swap "-2147483647765 4 5" "Error"
test_push_swap "214748364748385 28 47 29" "Error"
