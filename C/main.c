#include <stdio.h>
#include <stdlib.h>
#include "lib/Queue.h"
#include "lib/Graph.h"

void raio(Graph *g){
    int size = g->size, *distancia = NULL, maior = 0, menor, raio = -1;
    int excentricidades[size];
    for(int i =0; i< size; i++){
        distancia = BFS(g, i);
        for(int i = 0; i < size; i++){
            if(distancia[i] > maior){
                maior = distancia[i];
            }
        }
        excentricidades[i] = maior;
    }

    menor = excentricidades[0];
    for(int i = 0; i < size; i++){
        if(excentricidades[i] < menor){
            menor = excentricidades[i];
        }
    }

    raio = menor;
    printf("RAIO = %d\n", raio);
}


int main(int argc, char *argv[]){
    
    int V = 5;
    
    Graph *g = graph_from_file("grafo.g");
    print_graph(g);
    
    raio(g);

    return 0;
}
