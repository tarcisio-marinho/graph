
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
    int item, weight;
    struct AdjList *next;
}Adj;


Graph * max_flow_from_file(const char * path);
void ford_fulkerson(Graph *g, int s, int t);
void DFS(Graph * graph, int vertice);
void sub_dfs(Graph *graph, int vertice);
int * BFS(Graph * graph, int vertice);
void raio(Graph *);
Graph* create_graph(int quantityNodes);
Adj* new_adj_list(int vertex, int weight);
void add_edge(Graph *graph, int startVertex, int endVertex, int weight);
void print_graph(Graph *graph);
void destroy_graph(Graph *graph);
void clean_visits(Graph *graph);

Graph * graph_from_file(const char * path);
Graph * create_graph(int V);
void mat_from_file(const char * path);


#endif
