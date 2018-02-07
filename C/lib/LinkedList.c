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
        aux->prox = novo;   
    }
} 

void delete(LinkedList **l, int vertice){
    LinkedList *aux, *aux2;
    aux = *l;
    aux2 = *l;
    if(*l != NULL){
        while(aux!=NULL){
            if(vertice == aux->vertice){
                aux2->prox=aux->prox;
                free(aux);
            }
            aux2=aux2->prox;
            aux=aux->prox;
        }
    }
}

void destroy(LinkedList **l){
    LinkedList *aux;
    aux = *l;
    if(*l == NULL){
        
    }else if((*l)->prox == NULL){
        free(l);
    }else{
        while(*l != NULL){
            aux = *l;
            *l = aux->prox;
            free(aux);
        }
    }
}

void print(LinkedList *l){
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