#!/bin/bash

p1=1

# loop until p1 reaches 10000000000, multiplying it by 10 on each iteration
while [ $p1 -le 10000000000 ]
do
  echo "n = $p1"
  ./dlist_test "$p1" 
  echo ""
  ((p1*=10))
done
