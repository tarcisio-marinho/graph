
#ifndef __GRAPH__
#define __GRAPH__

#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

#define n 4


class Graph{

public:


    Graph * create_graph();
    void dfs();
    void bfs();
    void dijskras(int start, int end);
    void a_star(int start, int end);
    static Graph matrix_to_graph(int mat[][n]);
    void print();
    static Graph graph_from_file(const char * path);
    
private:
    std::vector<std::vector <int> > grafo;
    bool visited;
};


#endif