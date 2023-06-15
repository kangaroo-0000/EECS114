#include "heap.h"

void swapHeapNode(HeapNode** x, HeapNode** y) {
  HeapNode* temp = *x;
  *x = *y;
  *y = temp;
}
int isEmpty(PriorityQueue* minHeap) { return minHeap->heap_size == 0; }

PriorityQueue* createMinHeap(int capacity) {
  PriorityQueue* minHeap = malloc(sizeof(PriorityQueue));
  minHeap->pos = malloc(capacity * sizeof(int));
  minHeap->heap_size = 0;
  minHeap->capacity = capacity;
  minHeap->harr = malloc(capacity * sizeof(HeapNode*));
  return minHeap;
}

bool isInMinHeap(PriorityQueue* minHeap, int v) {
  if (minHeap->pos[v] < minHeap->heap_size) return true;
  return false;
}

void decreaseKey(PriorityQueue* minHeap, int v, float key) {
  int i = minHeap->pos[v];

  minHeap->harr[i]->key = key;

  while (i && minHeap->harr[i]->key < minHeap->harr[(i - 1) / 2]->key) {
    minHeap->pos[minHeap->harr[i]->vertex] = (i - 1) / 2;
    minHeap->pos[minHeap->harr[(i - 1) / 2]->vertex] = i;
    swapHeapNode(&minHeap->harr[i], &minHeap->harr[(i - 1) / 2]);

    // move to parent index
    i = (i - 1) / 2;
  }
}

void minHeapify(PriorityQueue* minHeap, int idx) {
  int smallest, left, right;
  smallest = idx;
  left = 2 * idx + 1;
  right = 2 * idx + 2;

  if (left < minHeap->heap_size &&
      minHeap->harr[left]->key < minHeap->harr[smallest]->key)
    smallest = left;

  if (right < minHeap->heap_size &&
      minHeap->harr[right]->key < minHeap->harr[smallest]->key)
    smallest = right;

  if (smallest != idx) {
    // The nodes to be swapped in min heap
    HeapNode* smallestNode = minHeap->harr[smallest];
    HeapNode* idxNode = minHeap->harr[idx];

    // Swap positions
    minHeap->pos[smallestNode->vertex] = idx;
    minHeap->pos[idxNode->vertex] = smallest;

    // Swap nodes
    swapHeapNode(&minHeap->harr[smallest], &minHeap->harr[idx]);

    minHeapify(minHeap, smallest);
  }
}

HeapNode* extractMin(PriorityQueue* minHeap) {
  if (isEmpty(minHeap)) return NULL;

  HeapNode* root = minHeap->harr[0];
  HeapNode* rootCopy = newMinHeapNode(root->vertex, root->key);

  // Replace root node with last node
  HeapNode* lastNode = minHeap->harr[minHeap->heap_size - 1];
  minHeap->harr[0] = lastNode;

  // Update position of last node
  minHeap->pos[root->vertex] = minHeap->heap_size - 1;
  minHeap->pos[lastNode->vertex] = 0;

  // Reduce heap size and heapify root
  --minHeap->heap_size;
  minHeapify(minHeap, 0);

  return rootCopy;
}