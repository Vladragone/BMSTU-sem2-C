 #!/bin/bash
 
clang -fsanitize=address -g -O0 -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -c -o test.o test.c
clang -fsanitize=address -g -O0 -fno-omit-frame-pointer -std=c99 -o test.exe test.o
