#!/bin/bash

assert_equals () {
  if [ "$1" = "$2" ]; then
    echo -e "$Green $Check_Mark Test Passed $Color_Off"
  else
    echo -e "$Red  Fail $Color_Off"
    echo -e "$Red  Output: $1  Expected: $2 $Color_Off"
    Errors=$((Errors  + 1))
    exit 1
  fi
}

response=$(./main.o d  2 + 2)
assert_equals "$response" 4

response=$(./main.o d  2 - 10)
assert_equals "$response" -8

response=$(./main.o b  3 + 1)
assert_equals "$response" 0000000000000100

response=$(./main.o x  11 - 1)
assert_equals "$response" A

response=$(./main.o h  11 - 1)
assert_equals "$response" "print error"
