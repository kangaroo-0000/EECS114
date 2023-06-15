#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#pragma once

typedef struct PriorityQueue {
  HeapNode** harr;  // array of elements
  int* pos;         // this is needed to decrease key
  int capacity;     // capacity of min heap
  int heap_size;    // Current number of elements in min heap
} PriorityQueue;

void swapHeapNode(HeapNode** x, HeapNode** y);
PriorityQueue* createMinHeap(int capacity);
bool isInMinHeap(PriorityQueue* minHeap, int v);
void decreaseKey(PriorityQueue* minHeap, int v, float key);
void minHeapify(PriorityQueue* minHeap, int idx);
HeapNode* extractMin(PriorityQueue* minHeap);
int isEmpty(PriorityQueue* minHeap);
