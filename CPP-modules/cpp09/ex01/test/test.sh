#!/bin/bash

printf "\nMain test:\n\n"

PASS=0
FAIL=0

check() {
  local desc="$1"
  local input="$2"
  local expected="$3"

  actual=$(./RPN "$input" 2>&1)
  if [ "$actual" = "$expected" ]; then
    printf "PASS  %-25s  %-20s  %s\n" "$desc" "$input" "$expected"
    ((PASS++))
  else
    printf "FAIL  %-25s  %-20s  expected: %s  got: %s\n" "$desc" "$input" "$expected" "$actual"
    ((FAIL++))
  fi
}

check "simple addition"        "3 4 +"              "7"
check "simple subtraction"     "9 3 -"              "6"
check "simple multiplication"  "3 4 *"              "12"
check "simple division"        "8 2 /"              "4"
check "chained operations"     "5 1 2 + 4 * + 3 -"  "14"
check "negative result"        "3 9 -"              "-6"
check "zero result"            "4 4 -"              "0"
check "division result float"  "7 2 /"              "3.5"

check "division by zero"       "4 0 /"              "Error: division by zero"
check "too many operators"     "1 +"                "Error: too many operators or not enough numbers"
check "not enough operators"   "1 2 3 +"            "Error: not enough operators or too many numbers"
check "invalid character"      "1 2 a +"            "Error: invalid character"
check "multi-digit number"     "12 3 +"             "Error: invalid character"
check "empty expression"       ""                   "Error: not enough operators or too many numbers"

echo ""
echo "Results: $PASS passed, $FAIL failed"

exit 0
