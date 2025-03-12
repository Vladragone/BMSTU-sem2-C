#!/bin/bash

if [ -z "$1" -o -z "$2" -o -z "$3" ]; then 
    exit 1 
fi 

touch out.txt
./comparator.sh <(../../test.exe "$(cat "$3")" < "$1") "$2"

if [ $? -eq 1 ]; then
    exit 0
else
    exit 1
fi
