//#include "lib/Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "lib/LinkedList.h"
int main(int argc, char *argv[]){
    
    LinkedList * lista = NULL;

    append(&lista, 10);
    append(&lista, 20);
    append(&lista, 30);
    append(&lista, 40);
    append(&lista, 50);
    append(&lista, 60);

    print(lista);
    
    delete(&lista, 10);
    print(lista);
    return 0;
}