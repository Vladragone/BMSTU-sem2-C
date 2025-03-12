#!/bin/bash

if [ -z "$1" ]; then 
    exit 1 
fi 

../../test.exe < $1 > out.txt
if [ $? -eq 1 ]; then
	rm out.txt
    exit 0
else
	rm out.txt
    exit 1
fi

