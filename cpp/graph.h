
#ifndef __GRAPH__
#define __GRAPH__

#include<iostream>
#include<vector>

#define n 3

using namespace std;

class Graph{

public:
    vector<vector <int> > graph;
    bool visited;

    Graph * create_graph();
    void dfs();
    void bfs();
    void dijskras(int start, int end);
    void a_star(int start, int end);
    Graph * matrix_to_graph(int mat[][n]);

};


#endif