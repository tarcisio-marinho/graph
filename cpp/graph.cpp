#include "graph.h"



Graph::Graph * create_graph(){
    
}


Graph::void dfs(){
    
}


Graph::void bfs(){
    
}


Graph::void dijskras(int start, int end){
    
}


Graph::void a_star(int start, int end){
    
}


Graph::static Graph matrix_to_graph(int mat[][n]){
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


Graph::void print(){
    for(int i = 0; i < n; i++){
        cout << i << "-> ";
        for (int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] != -1)
                cout << j << " " ;
        }
        cout << endl;
    }
}

