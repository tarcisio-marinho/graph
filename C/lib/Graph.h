
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

Graph * from_file(const char * path);
Graph* create_graph(int V);
void add_edge(Graph* graph, int src, int dest);
void print_graph(Graph* graph);
void mat_from_file(const char * path);

#endif
