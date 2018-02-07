
#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include<stdio.h>

typedef struct no{
    int vertice;
    struct no *prox;
}LinkedList;

void end_insertion(LinkedList **l, int vertice);

#endif