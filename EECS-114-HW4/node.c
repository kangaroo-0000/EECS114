#include "node.h"

HeapNode* newMinHeapNode(int vertex, float key) {
  HeapNode* minHeapNode = (HeapNode*)malloc(sizeof(HeapNode));
  minHeapNode->vertex = vertex;
  minHeapNode->key = key;
  return minHeapNode;
}

Node* createNode(int v, float w) {
  Node* newNode = malloc(sizeof(Node));
  newNode->vertex = v;
  newNode->weight = w;
  newNode->next = NULL;
  return newNode;
}