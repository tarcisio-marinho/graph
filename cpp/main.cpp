#include<iostream>
#include<vector>
#include "graph.h"


int main(){
    vector<vector<int> > matrix;
    int mat[3][3] = {{1, 0, 0}, {1, 0, 1}, {0, 1, 0}};

    
    matrix = matrix_to_adj(mat);

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << "i: " << i << " - j: " << j  << " valor: "<< matrix[i][j] << endl;
        }
        cout << endl;
    }


    
    return 0;
}