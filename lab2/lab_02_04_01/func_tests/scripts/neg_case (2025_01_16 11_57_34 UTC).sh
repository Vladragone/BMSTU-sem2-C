#!bin/bash

if [ -z "$1" ]; then 
    exit 1 
fi 

../../app.exe < $1

if [ $? -eq 1 ]; then
    exit 0
else
    exit 1
fi

