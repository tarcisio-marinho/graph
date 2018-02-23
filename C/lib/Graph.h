
#ifndef _GRAPH_
#define _GRAPH_

#include "Queue.h"
#include<stdio.h>
#include<stdlib.h>


typedef struct AdjListNode{
    int dest;
    struct AdjListNode* next;
}AdjListNode;
 
// A structure to represent an adjacency list
typedef struct AdjList{
    AdjListNode *head;  // pointer to head node of list
}AdjList;

 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
typedef struct Graph{
    int V;
    AdjList* array;
}Graph;


Graph* createGraph(int V);
Graph* createGraph(int V);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);


#endif
