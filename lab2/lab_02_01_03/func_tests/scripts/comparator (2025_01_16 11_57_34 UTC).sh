#!/bin/bash 
a=$1 
b=$2 
if [ -z "$1" -o -z "$2" ]; then 
    exit 1
fi 
cp $a file1_temp 
cp $b file2_temp 
awk '^-?[0-9]+(\.[0-9]+)?$' file2_temp > file2_temp2 
awk '^-?[0-9]+(\.[0-9]+)?$' file1_temp > file1_temp2 

if cmp -s file1_temp2 file2_temp2; then
    rm file1_temp 
    rm file1_temp2 
    rm file2_temp 
    rm file2_temp2
    exit 0
else 
    rm file1_temp 
    rm file1_temp2 
    rm file2_temp 
    rm file2_temp2
    exit 1
fi 
