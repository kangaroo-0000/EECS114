/**
 *  \file insertion-sort.cc
 *
 *  \brief Implement your insertion sort in this file.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.hh"

void mySort (int N, keytype* A)
{
  /* Lucky you, you get to start from scratch */
  int i, j;
  keytype temp;
  for (i = 1; i < N; i++) {
    temp = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > temp) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = temp;
  }
}

/* eof */
