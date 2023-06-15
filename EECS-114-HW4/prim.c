#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "graph.h"
#include "heap.h"
#include "node.h"

typedef struct MSTResult {
  int* parent;
  float totalWeight;
} MSTResult;

void readGraph(Graph* graph, char* fileName);
MSTResult* primMST(Graph* graph);
void writeMSTToFile(Graph* graph, MSTResult* result);

void readGraph(Graph* graph, char* fileName) {
  FILE* file = fopen(fileName, "r");
  if (file == NULL) {
    printf("Error opening file!\n");
    return;
  }

  // ignore the first line
  int dummy;
  fscanf(file, "%d", &dummy);

  int src, dest;
  float weight;
  while (fscanf(file, "%d %d %f", &src, &dest, &weight) == 3) {
    addEdge(graph, src, dest, weight);
  }

  fclose(file);
}

void writeMSTToFile(Graph* graph, MSTResult* result) {
  FILE* file = fopen("mst.txt", "w");

  if (file == NULL) {
    printf("Error opening file!\n");
    return;
  }

  fprintf(file, "%d\n", (int)result->totalWeight);

  for (int i = 0; i < graph->numVertices; i++) {
    if (result->parent[i] == -1) continue;
    float weight = getEdgeWeight(graph, result->parent[i], i);
    fprintf(file, "%d %d %f\n", result->parent[i], i, weight);
  }

  fclose(file);
  free(result->parent);
  free(result);
}

MSTResult* primMST(Graph* graph) {
  HeapNode* minHeapNode;
  // Time measurement
  clock_t start, end;
  double cpu_time_used;
  start = clock();

  int V = graph->numVertices;
  int* parent = malloc(sizeof(int) * V);
  float* key = malloc(sizeof(float) * V);

  PriorityQueue* minHeap = createMinHeap(V);

  for (int v = 0; v < V; ++v) {
    parent[v] = -1;
    key[v] = INT_MAX;
    minHeap->harr[v] = newMinHeapNode(v, key[v]);
    minHeap->pos[v] = v;
  }

  key[0] = 0;
  minHeap->harr[0] = newMinHeapNode(0, key[0]);
  minHeap->pos[0] = 0;
  minHeap->heap_size = V;

  while (!isEmpty(minHeap)) {
    minHeapNode = extractMin(minHeap);
    int u = minHeapNode->vertex;

    Node* pCrawl = graph->adjLists[u];
    while (pCrawl != NULL) {
      int v = pCrawl->vertex;

      if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v]) {
        key[v] = pCrawl->weight;
        parent[v] = u;
        decreaseKey(minHeap, v, key[v]);
      }
      pCrawl = pCrawl->next;
    }
  }
  free(minHeapNode);

  float totalWeight = 0;
  for (int i = 0; i < V; ++i) {
    if (parent[i] == -1) continue;
    totalWeight += key[i];
  }

  // End time measurement
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("Time taken to construct MST: %f seconds\n", cpu_time_used);

  MSTResult* result = malloc(sizeof(MSTResult));
  result->parent = parent;
  result->totalWeight = totalWeight;

  free(key);
  free(minHeap->harr);
  free(minHeap->pos);
  free(minHeap);

  return result;
}

int main(int argc, char** argv) {
  int vertices;
  char* fileName = NULL;

  if (argc == 2) {
    fileName = argv[1];
  } else {
    printf("Usage: ./prim <file_name>\n");
    return -1;
  }

  FILE* file = fopen(fileName, "r");
  if (file == NULL) {
    printf("Error opening file!\n");
    return -1;
  }

  // Read the number of vertices from the first line
  fscanf(file, "%d", &vertices);
  fclose(file);

  Graph* graph = createGraph(vertices);
  readGraph(graph, fileName);
  MSTResult* result = primMST(graph);
  writeMSTToFile(graph, result);
  free(graph->adjLists);
  free(graph);

  return 0;
}
