
#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int vertice;
    struct no *prox;
}LinkedList;

void append(LinkedList **l, int vertice);
void delete(LinkedList **l, int vertice);
void destroy(LinkedList **l);
void print(LinkedList *l);

#endif