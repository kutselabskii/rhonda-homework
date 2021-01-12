#!/usr/bin/env bash

rm input.txt
rm output.txt
g++ -o a.out main.cpp
echo 100000 > input.txt
./a.out
printf "\n\n"
cat output.txt
printf '\n'
