#!/bin/bash
gcc -O3 -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -c -o inout.o inout.c
gcc -O3 -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -c -o operation.o operation.c
gcc -O3 -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -c -o test.o test.c
gcc -O3 -fno-omit-frame-pointer -std=c99  test.o inout.o operation.o -o test.exe -lm