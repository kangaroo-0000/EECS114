#!/bin/bash
# runs the insertion sort program for sizes 2^0 to 2^20 
for ((i=0; i<=20; i++))
do
    size=$((2**i))
    echo "Sorting array of size $size"
    ./insertion-sort $size
done