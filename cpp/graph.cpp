#include "graph.h"



Graph * Graph::create_graph(){
    
}

Graph Graph::matrix_to_graph(int mat[][n]){
    Graph adj;
    for(int i = 0; i < n; i++){
        std::vector<int> novo;
        for(int j = 0; j < n; j++){
            if(mat[i][j] != 0){
                novo.push_back(mat[i][j]);
            }else{
                novo.push_back(-1);
            }
        }
        adj.grafo.push_back(novo);
    }

    return adj;
}


void Graph::print(){
    for(int i = 0; i < n; i++){
        std::cout << i << "-> ";
        for (int j = 0; j < grafo[i].size(); j++){
            std::cout << j << " " ;
        }
        std::cout << std::endl;
    }
}

Graph Graph::graph_from_file(const char * path){
    FILE * f = fopen(path, "r");
    if(f == NULL){
        std::cout << "Arquivo não existe" << std::endl;
        exit(-1);
    }

    Graph adj;
    int size;
    fscanf(f, "%d", &size);
    int mat[size][size];

    for (int i = 0; i < size; i++){
        std::vector<int> novo;
        std::cout << i << "-> ";
        for(int j = 0; j < size; j++){
            int valor;
            fscanf(f, "%d", &valor);
            if(valor == 1){
                novo.push_back(j);
                std::cout << j << " " ;
            }
        }
        std::cout << std::endl;
        adj.grafo.push_back(novo);
    }
    
    return adj;
}


void Graph::bfs(){
    
}


void Graph::dfs(){
    
}


void Graph::dijskras(int start, int end){
    
}


void Graph::a_star(int start, int end){
    
}
