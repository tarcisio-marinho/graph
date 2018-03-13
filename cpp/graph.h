
#ifndef __GRAPH__
#define __GRAPH__

#include<iostream>
#include<vector>
#include <queue>

#define n 4


class Graph{

public:
    std::vector<std::vector <int> > grafo;
    bool visited;

    Graph * create_graph();
    void dfs();
    void bfs();
    void dijskras(int start, int end);
    void a_star(int start, int end);
    static Graph matrix_to_graph(int mat[][n]);
    void print();
    static void mat_from_file(const char * path);

};


#endif