//#include "lib/Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "lib/Queue.h"
#include "lib/Graph.h"


int main(int argc, char *argv[]){
    
    int V = 5;
    
    Graph *g = graph_from_file("grafo.g");
    print_graph(g);
    
    //mat_from_file("grafo.g");
    // Graph *g = graph_from_file("grafo.g");
    // print_graph(g);
 
    return 0;
}
