//#include "lib/Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "lib/LinkedList.h"
#include "lib/Queue.h"
int main(int argc, char *argv[]){
    
    Queue * fila = NULL;
    int valor;

    create_queue(fila);

    enqueue(fila, 10);
    valor = dequeue(fila);

    printf("%d\n", valor);
    return 0;
}