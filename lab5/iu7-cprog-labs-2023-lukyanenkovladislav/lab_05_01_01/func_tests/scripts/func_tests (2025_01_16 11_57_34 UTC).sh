#!/bin/bash
cd ../../
./build_release.sh
cd func_tests/scripts
positive_tests=($(ls ../data | grep "^pos_")) 
len=$(ls -1 ../data | grep "^pos" | wc -l)
flag=0
num=1
echo ##############
echo POSITIVE TESTS
echo ##############

# Прогон позитивных тестов

for ((i = 0; i < $len; i = i + 2))
do
    ./pos_case.sh "../data/${positive_tests[$i]}" "../data/${positive_tests[$i+1]}"

    if [[ $? -eq 0  ]]; then
        echo POSITIVE TEST$num: PASSED
    else
        echo POSITIVE TEST$num: FAILED
        flag=1
    fi
	num=$(($num+1))
done
echo


num=1
length=$(ls -1 ../data | grep "^neg" | wc -l)
negative_tests=($(ls ../data | grep "^neg_")) 
echo ##############
echo NEGATIVE TESTS
echo ##############
echo

# Прогон негативных тестов

for ((i = 0; i < $length; i = i + 2))
do
    ./neg_case.sh "../data/${negative_tests[i]}"
    if [[ $? -eq 0  ]]; then
        echo NEGATIVE TEST$num: PASSED
    else
        echo NEGATIVE TEST$num: FAILED
        flag=1

    fi
    
    num=$(($num+1))
done
echo

echo ##############
echo     RESULT
echo ##############
echo
if [[ $flag -eq 0 ]]; then
    echo TESTS PASSED.
	exit 0
else
    echo TESTS FAILED.
	exit 1
fi