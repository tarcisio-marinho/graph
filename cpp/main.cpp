#include<iostream>
#include<vector>
#include "graph.h"

#define n 4
using namespace std;

vector<vector<int> > matrix_to_graph(int mat[n][n]){
    
}


int main(){
    Graph matrix;
    int mat[n][n] = {{0, 1, 0, 0}, {1, 0, 1, 1}, {0, 1, 0, 0}, {0, 1, 0, 0}};

    
    matrix = matrix_to_graph(mat);

    matrix.print();


    
    return 0;
}