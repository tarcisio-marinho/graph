#include "LinkedList.h"

void append(LinkedList **l,int vertice){ 
    LinkedList *aux,*novo;

    novo = (LinkedList*)malloc(sizeof(LinkedList));
    novo->prox = NULL;
    novo->vertice = vertice;

    if(*l == NULL)    *l = novo;
    else{
        aux = *l;
        while(aux->prox != NULL){ 
            aux = aux->prox;
        }
    }
    aux->prox = novo;
} 

void exibir_todos(LinkedList *l){
    LinkedList *novo;
    if(l == NULL){
        printf("Vazia\n");
    }else{
        novo = l;
        while(novo->prox != NULL){
            printf("%d\n", novo->vertice);
            novo = novo->prox; 
        } 
        printf("\n\n");
    } 
}