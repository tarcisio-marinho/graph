
#ifndef _GRAPH_
#define _GRAPH_

#include "Queue.h"
#include<stdio.h>
#include<stdlib.h>


typedef struct AdjListNode{
    int dest;
    struct AdjListNode* next;
}AdjListNode;
 

typedef struct AdjList{
    AdjListNode *head;
}AdjList;

 
typedef struct Graph{
    int V;
    AdjList* array;
}Graph;


Graph* createGraph(int V);
Graph* createGraph(int V);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);


#endif
