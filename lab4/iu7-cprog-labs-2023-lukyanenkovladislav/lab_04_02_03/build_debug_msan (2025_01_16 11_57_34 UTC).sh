 #!/bin/bash
 
clang -fsanitize=memory -g -O0 -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -c -o test.o test.c
clang -fsanitize=memory -g -O0 -fno-omit-frame-pointer -std=c99 -o test.exe test.o
