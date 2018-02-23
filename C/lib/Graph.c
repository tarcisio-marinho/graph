#include<stdio.h>
#include<stdlib.h>

#include "Graph.h"

 
AdjListNode* newAdjListNode(int dest){
    AdjListNode* newNode =
            (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
Graph* createGraph(int V){
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
 
    graph->array = (AdjList*) malloc(V * sizeof(AdjList));
 
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
void addEdge(Graph* graph, int src, int dest){
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
 
void printGraph(Graph* graph){
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
