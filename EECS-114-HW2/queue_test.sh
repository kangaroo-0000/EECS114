#!/bin/bash

p1=1
p2=10000

# loop until p1 reaches 1000000, multiplying it by 10 on each iteration
while [ $p1 -le 1000000 ]
do
  echo "n = $p1, t = $p2"
  ./queue_test "$p1" "$p2"
  echo ""
  ((p1*=10))
done
