/**
 *  \file insertion-sort-bisearch.cc
 *
 *  \brief Implement your insertion sort with binary search in this file.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.hh"

void mySort (int N, keytype* A)
{
  /* Lucky you, you get to start from scratch */
   int i, j, k, l, r, m; 
  keytype temp;
  for (i = 1; i < N; i++) {
    temp = A[i]; 
    l = 0; 
    r = i - 1; 
    while (l <= r) {
      m = (l + r) / 2; 
      if (A[m] < temp) {
        l = m + 1; 
      } else {
        r = m - 1; 
      }
    }
    for (j = i; j > l; j--) {
      A[j] = A[j - 1]; 
    }
    A[l] = temp; 
  }
}


/* eof */
