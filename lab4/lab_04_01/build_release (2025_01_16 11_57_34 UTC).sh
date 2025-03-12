#!/bin/bash
gcc -O3 -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -c -o func.o func.c
gcc -O3 -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -c -o test.o test.c
gcc -O3 -fno-omit-frame-pointer -std=c99  test.o func.o -o test.exe -lm