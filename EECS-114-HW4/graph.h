#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#pragma once

typedef struct Graph {
  int numVertices;
  Node** adjLists;
} Graph;

Node* createNode(int v, float w);

Graph* createGraph(int vertices);

void addEdge(Graph* graph, int src, int dest, float weight);

float getEdgeWeight(Graph* graph, int vertex1, int vertex2);
