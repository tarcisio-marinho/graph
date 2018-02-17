#include "graph.h"



Graph * create_graph(){
    
}


void dfs(){
    
}


void bfs(){
    
}


void dijskras(int start, int end){
    
}


void a_star(int start, int end){
    
}


Graph matrix_to_graph(int mat[][n]){
    Graph adj;
    for(int i = 0; i < n; i++){
        vector<int> novo;
        for(int j = 0; j < n; j++){
            if(mat[i][j] != 0){
                novo.push_back(mat[i][j]);
            }else{
                novo.push_back(-1);
            }
        }
        adj.matrix.push_back(novo);
    }

    return adj;
}


void print(){
    for(int i = 0; i < n; i++){
        cout << i << "-> ";
        for (int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] != -1)
                cout << j << " " ;
        }
        cout << endl;
    }
}

