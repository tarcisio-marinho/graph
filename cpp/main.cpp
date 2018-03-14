#include<iostream>
#include<vector>
#include "graph.h"

#define n 4

int main(){
    
    //int mat[n][n] = {{0, 1, 0, 0}, {1, 0, 1, 1}, {0, 1, 0, 0}, {0, 1, 0, 0}};

    Graph g = Graph::graph_from_file("grafo.g");
    std::cout << std::endl;
    g.print();
    //Graph matrix = Graph::matrix_to_graph(mat);


    ///matrix.print();


    
    return 0;
}