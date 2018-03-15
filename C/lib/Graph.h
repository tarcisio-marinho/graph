
#ifndef _GRAPH_
#define _GRAPH_

#include "Queue.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct graph{
    int size;
    struct AdjList **vertices;
    bool *visited;
}Graph;

typedef struct AdjList{
    int item;
    struct AdjList *next;
}Adj;


void BFS(Graph * graph, int vertice);
Graph* create_graph(int quantityNodes);
Adj* new_adj_list(int vertex);
void add_edge(Graph *graph, int startVertex, int endVertex);
void print_graph(Graph *graph);
void destroy_graph(Graph *graph);
void clean_visits(Graph *graph);

Graph * graph_from_file(const char * path);
Graph * create_graph(int V);
void mat_from_file(const char * path);


#endif
