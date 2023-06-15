#include <stdio.h>
#include <stdlib.h>
#pragma once

typedef struct Node {
  int vertex;
  float weight;
  struct Node* next;
} Node;

typedef struct HeapNode {
  int vertex;
  float key;
} HeapNode;

HeapNode* newMinHeapNode(int vertex, float key);
Node* createNode(int v, float w);