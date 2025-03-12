#!/bin/bash

if [ -z "$1" -o -z "$2" ]; then 
    exit 1 
fi 
touch out.txt
./comparator.sh <(../../test.exe "$(cat "$2")" < "$1") out.txt

if [ $? -eq 0 ]; then
	rm out.txt
    exit 0
else
	rm out.txt
    exit 1
fi
