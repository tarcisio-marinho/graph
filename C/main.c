#include <stdio.h>
#include <stdlib.h>
#include "lib/Queue.h"
#include "lib/Graph.h"


int main(int argc, char *argv[]){
    
    int V = 5;
    
    Graph *g = max_flow_from_file("grafo2.g");
    print_graph(g);
    

    return 0;
}
