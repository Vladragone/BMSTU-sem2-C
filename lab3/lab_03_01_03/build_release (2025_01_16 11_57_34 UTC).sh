#!/bin/bash
gcc -O3 -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -c -o inout.o inout.c
gcc -O3 -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -c -o find_mon.o find_mon.c
gcc -O3 -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -c -o test.o test.c
gcc -O3 -fno-omit-frame-pointer -std=c99  test.o inout.o find_mon.o -o test.exe -lm
