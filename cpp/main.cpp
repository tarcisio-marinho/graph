#include<iostream>
#include<vector>
//#include "graph.h"
#define n 4
using namespace std;

vector<vector<int> > matrix_to_graph(int mat[n][n]){
    vector<vector<int> > adj;
    for(int i = 0; i < n; i++){
        vector<int> novo;
        for(int j = 0; j < n; j++){
            if(mat[i][j] != 0){
                novo.push_back(mat[i][j]);
            }
        }
        adj.push_back(novo);
    }

    return adj;
}


int main(){
    vector<vector<int> > matrix;
    int mat[n][n] = {{0, 1, 0, 0}, {1, 0, 1, 1}, {0, 1, 0, 0}, {0, 1, 0, 0}};

    
    matrix = matrix_to_graph(mat);

    for(int i = 0; i < n; i++){
        cout << i << "-> ";
        for (int j = 0; j < matrix[i].size(); j++){
            //if(matrix[i][j] != -1)
            cout << j << " " ;
        }
        cout << endl;
    }


    
    return 0;
}