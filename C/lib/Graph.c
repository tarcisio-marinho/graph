#include<stdio.h>
#include<stdlib.h>

#include "Graph.h"


void mat_from_file(const char * path){
    FILE * f = fopen(path, "r");
    if(f == NULL){
        printf("Arquivo inexistente\n");
        exit(-1);
    }
    
    int size;
    fscanf(f, "%d", &size);
    int mat[size][size];

    for (int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            fscanf(f, "%d", &mat[i][j]);
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}


Graph * from_file(const char * path){
    FILE * f = fopen(path, "r");
    if(f == NULL){
        printf("Arquivo inexistente\n");
        exit(-1);
    }
    
    int size;
    fscanf(f, "%d", &size);
    Graph * g = create_graph(size);

    for (int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int valor;
            fscanf(f, "%d", &valor);
            if(valor == 1){
                add_edge(g, i, j);
            }
        }
    }
    return g;   
}


AdjListNode* newAdjListNode(int dest){
    AdjListNode* newNode =
            (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 

Graph* create_graph(int V){
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
 
    graph->array = (AdjList*) malloc(V * sizeof(AdjList));
 
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 

void add_edge(Graph* graph, int src, int dest){
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
 

void print_graph(Graph* graph){
    int v;
    for (v = 0; v < graph->V; ++v){
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n%d", v);
        while (pCrawl){
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
