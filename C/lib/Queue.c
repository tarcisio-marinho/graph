#include "Queue.h"

typedef struct pedido {
     int numero;
     char descricao [100];
} Pedido;

typedef struct noQueue {
       Pedido info;
       struct noQueue *prox;
} NoQueue;

typedef struct descritor {
      NoQueue * inicio, * fim;
}Descritor;

typedef Descritor * Queue;

void createQueue (Queue * fila) {
    *fila = (Descritor *) malloc (sizeof(Descritor));
    (*fila)->inicio = NULL;
    (*fila)->fim = NULL;
}


void enQueue (Queue * fila, Pedido valor) {
    NoQueue * novo;
    novo = (NoQueue *) malloc (sizeof(NoQueue));
    novo->info = valor;
    novo->prox = NULL;
    if ((*fila)->inicio == NULL) {
        (*fila)->inicio = novo;
        (*fila)->fim = novo;
    }
    else {
        (*fila)->fim->prox = novo;
        (*fila)->fim = novo;
    }
}

Pedido deQueue (Queue * fila) {
    NoQueue * aux;
    Pedido valor;
    aux = (*fila)->inicio;
    (*fila)->inicio = aux->prox;
    valor = aux->info;
    if ((*fila)->inicio == NULL) {
        (*fila)->fim = NULL;
    }
    free (aux);
    return valor;
}

Pedido head (Queue fila) {
    return fila->inicio->info;
}

int isEmpty (Queue fila) {
    if (fila->inicio == NULL) {
        return true;
    }
    else {
        return false;
    }
}

int isFull (Queue fila) {
    return false;
}

void destroyQueue (Queue * fila) {
    NoQueue * aux;
    while ((*fila)->inicio != NULL) {
        aux= (*fila)->inicio;
        (*fila)->inicio = aux->prox;
        free (aux);
    }
    free (*fila);
    *fila = NULL;
}
