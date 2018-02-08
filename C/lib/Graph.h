
#ifndef _GRAPH_
#define _GRAPH_

#include "LinkedList.h"
#include "Queue.h"
#include<stdio.h>
#include<stdlib.h>


// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
typedef struct Graph{
    int V;
    LinkedList* array;
}Graph;

void create_graph(Graph **grafo);
void populate_graph(Graph *grafo);

#endif