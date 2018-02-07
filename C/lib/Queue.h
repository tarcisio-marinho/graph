
#ifndef _QUEUE_
#define _QUEUE_

#include <stdio.h>
#include <stdlib.h>

typedef struct noqueue {
       int info;
       struct noqueue *prox;
} noQueue;

typedef struct descritor {
      noQueue * inicio, * fim;
}Descritor;

typedef Descritor * Queue;



/* Basic Queue Operations */
void create_queue(Queue * fila);
void enqueue(Queue * fila, int valor);
int dequeue(Queue * fila);
int head(Queue fila);
int is_empty(Queue fila);
int is_full(Queue fila);
void destroy_queue(Queue * fila);

#endif