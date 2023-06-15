/**
 *  \file mergesort.cc
 *
 *  \brief Implement your mergesort in this file.
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
  if (N <= 1) {
    return;
  }
  int mid = N / 2;
  keytype* left = newKeys(mid);
  keytype* right = newKeys(N - mid);
  for (i = 0; i < mid; i++) {
    left[i] = A[i];
  }
  for (i = mid; i < N; i++) {
    right[i - mid] = A[i];
  }
  mySort(mid, left);
  mySort(N - mid, right);
  i = 0;
  j = 0;
  k = 0;
  while (i < mid && j < N - mid) {
    if (left[i] < right[j]) {
      A[k] = left[i];
      i++;
    } else {
      A[k] = right[j];
      j++;
    }
    k++;
  }
  while (i < mid) {
    A[k] = left[i];
    i++;
    k++;
  }
  while (j < N - mid) {
    A[k] = right[j];
    j++;
    k++;
  }
  delete[] left;
  delete[] right;

}

/* eof */
