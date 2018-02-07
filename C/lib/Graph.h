
#ifndef _GRAPH_
#define _GRAPH_

#include "LinkedList.h"
#include "Queue.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct graph{
    LinkedList *start;
    int size;
}Graph;

void create_graph(Graph **grafo);
void populate_graph(Graph *grafo);

#endif