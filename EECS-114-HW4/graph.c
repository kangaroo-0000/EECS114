#include "graph.h"

#include <assert.h>

Graph* createGraph(int vertices) {
  Graph* graph = malloc(sizeof(Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(Node*));

  for (int i = 0; i < vertices; i++) graph->adjLists[i] = NULL;

  return graph;
}

void addEdge(Graph* graph, int src, int dest, float weight) {
  assert(!(src < 0 || src >= graph->numVertices || dest < 0 ||
           dest >= graph->numVertices));
  Node* newNode = createNode(dest, weight);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  newNode = createNode(src, weight);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

float getEdgeWeight(Graph* graph, int vertex1, int vertex2) {
  assert(graph != NULL);
  assert(graph->adjLists != NULL);
  assert(vertex1 >= 0 && vertex1 < graph->numVertices);

  // Check the adjacency list of vertex1 for vertex2
  Node* pCrawl = graph->adjLists[vertex1];
  while (pCrawl != NULL) {
    if (pCrawl->vertex == vertex2) {
      return pCrawl->weight;
    }
    pCrawl = pCrawl->next;
  }
  return -1;
}
