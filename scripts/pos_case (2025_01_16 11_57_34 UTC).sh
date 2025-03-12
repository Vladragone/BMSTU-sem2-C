#!bin/bash

if [ -z "$1" -o -z "$2" ]; then 
    exit 1 
fi 

touch out.txt
../../app.exe < $1 > out.txt
./comparator.sh out.txt $2

if [ $? -eq 0 ]; then
    exit 0
else
    exit 1
fi
