
#ifndef __GRAPH__
#define __GRAPH__

#include<iostream>
#include<vector>

using namespace std;

class Graph{

public:
    vector<vector <int> > graph;
    int n;

    Graph * create_graph(int n);
    void dfs();
    void bfs();
    void dijskras(int start, int end);
    void a_star(int start, int end);

};





#endif