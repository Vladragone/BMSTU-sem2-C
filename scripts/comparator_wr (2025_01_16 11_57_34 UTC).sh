 #!/bin/bash 
a=$1 
b=$2 
if [ -z "$1" -o -z "$2" ]; then 
    exit 1 
fi 
cp $a file1_temp 
cp $b file2_temp 
sed -n -i '/Result: /,$p' file1_temp
sed -n -i '/Result: /,$p' file2_temp
sed -i 's/Result: /\n/1' <<< $a file1_temp 
sed -i 's/Result: /\n/1' <<< $b file2_temp 
sed -i "1d" file1_temp
sed -i "1d" file2_temp

if cmp -s file1_temp file2_temp; then
    rm file1_temp 
    rm file2_temp 
    exit 0
else 
    rm file1_temp 
    rm file2_temp 
    exit 1
fi 
