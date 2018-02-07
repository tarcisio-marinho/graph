#include "Queue.h"


void create_queue(Queue * fila) {
    *fila = (Descritor *) malloc (sizeof(Descritor));
    (*fila)->inicio = NULL;
    (*fila)->fim = NULL;
}

void enqueue(Queue * fila, int valor) {
    noQueue * novo;
    novo = (noQueue *) malloc (sizeof(noQueue));
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

int dequeue(Queue * fila) {
    noQueue * aux;
    int valor;
    aux = (*fila)->inicio;
    (*fila)->inicio = aux->prox;
    valor = aux->info;
    if ((*fila)->inicio == NULL) {
        (*fila)->fim = NULL;
    }
    free (aux);
    return valor;
}

int head(Queue fila) {
    return fila->inicio->info;
}

int is_empty(Queue fila) {
    if (fila->inicio == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_full(Queue fila) {
    return 0;
}

void destroy_queue(Queue * fila) {
    noQueue * aux;
    while ((*fila)->inicio != NULL) {
        aux= (*fila)->inicio;
        (*fila)->inicio = aux->prox;
        free (aux);
    }
    free (*fila);
    *fila = NULL;
}
