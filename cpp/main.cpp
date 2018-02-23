#include<iostream>
#include<vector>
#include "graph.h"

#define n 4
using namespace std;

int main(){
    int mat[n][n] = {{0, 1, 0, 0}, {1, 0, 1, 1}, {0, 1, 0, 0}, {0, 1, 0, 0}};

    
    Graph matrix = Graph::matrix_to_graph(mat);

    matrix.print();


    
    return 0;
}