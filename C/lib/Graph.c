
#include "Graph.h"

int min(int a, int b){
    return !(b<a)?a:b; 
}

int min_cut_bfs(int rGraph[V][V], int s, int t, int parent[]){
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    Queue *q;
    create_queue(&q);
    enqueue(&q, s);
    visited[s] = true;
    parent[s] = -1;
 
    while (!is_empty(q)){
        int u = head(q);
        dequeue(&q);
 
        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                enqueue(&q, v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    return (visited[t] == true);
}

void min_cut_dfs(int rGraph[V][V], int s, bool visited[]){
    visited[s] = true;
    for (int i = 0; i < V; i++)
       if (rGraph[s][i] && !visited[i])
           min_cut_dfs(rGraph, i, visited);
}

void min_cut(const char *path){
    int u, v;

    FILE * f = fopen(path, "r");
    if(f == NULL){
        printf("Arquivo inexistente\n");
        exit(-1);
    }
    
    // Create empty graph
    int graph[V][V];
    for(int i = 1; i < V; i++){
        for (int j = 1; j < V; j++){
            graph[i][j] = 0;
        }
    }
    
    int s, t, qtd_arestas, aux, aux2, capacidade;
    fscanf(f, "%d", &s); // origem
    fscanf(f, "%d", &t); // destino
    fscanf(f, "%d", &qtd_arestas); // quantidade de arestas
    
    // populate graph
    while(!feof(f)){
        fscanf(f, "%d", &aux); // v1
        fscanf(f, "%d", &aux2); // v2
        fscanf(f, "%d", &capacidade); // origem

        graph[aux][aux2] = capacidade;
    }
    print_matrix(graph);

    // ṕopulate grafo residual
    int max_flow = 0;
    int residual[V][V]; 
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             residual[u][v] = graph[u][v];
 
    int parent[V];  
 
   
    while (min_cut_bfs(residual, s, t, parent)){
        int path_flow = 999999999;
        for (v=t; v!=s; v=parent[v]){
            u = parent[v];
            path_flow = min(path_flow, residual[u][v]);
        }
 
        for (v=t; v != s; v=parent[v]){
            u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    printf("Fluxo máximo: %d\n\n", max_flow);
 
    bool visited[V];
    memset(visited, false, sizeof(visited));
    min_cut_dfs(residual, s, visited);
    
    printf("Corte mínimo:\n");
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (visited[i] && !visited[j] && graph[i][j]){
                printf("%d - %d\n", i, j);
            }
        }
    }

    return;
}


Graph * max_flow_from_file(const char * path){
    FILE * f = fopen(path, "r");
    if(f == NULL){
        printf("Arquivo inexistente\n");
        exit(-1);
    }
    
    int size, s, t, qtd_arestas, aux, aux2, capacidade;
    fscanf(f, "%d", &s); // origem
    fscanf(f, "%d", &t); // destino
    fscanf(f, "%d", &qtd_arestas); // quantidade de arestas
    
    Graph * g = create_graph(13); // grafo com 13 vertices
    while(!feof(f)){
        fscanf(f, "%d", &aux);
        fscanf(f, "%d", &aux2); 
        fscanf(f, "%d", &capacidade); // origem

        add_edge(g, aux, aux2, capacidade);
    }

    return g;   
}


void raio(Graph *g){
    int size = g->size, *distancia = NULL, maior = 0, menor, raio = -1;
    int excentricidades[size];
    for(int i =0; i< size; i++){
        distancia = BFS(g, i);
        for(int i = 0; i < size; i++){
            if(distancia[i] > maior){
                maior = distancia[i];
            }
        }
        excentricidades[i] = maior;
    }

    menor = excentricidades[0];
    for(int i = 0; i < size; i++){
        if(excentricidades[i] < menor){
            menor = excentricidades[i];
        }
    }

    raio = menor;
    printf("RAIO = %d\n", raio);
}


int * BFS(Graph * graph, int vertice){
    if(graph == NULL)   return NULL;

    int *distancia = NULL;
    distancia = (int *)malloc(sizeof(int)*graph->size);
    Queue q;

    create_queue(&q);
    clean_visits(graph);

    graph->visited[vertice] = true;
    enqueue(&q, vertice);

    while(!is_empty(q)){
        int valor = dequeue(&q);

        for(int i = 0; i < graph->size; i++){
            if(!graph->visited[i]){
                graph->visited[i] = true;
                distancia[i] = distancia[valor] + 1;
                enqueue(&q, i);
            }
        }
    }

    return distancia;
}


void DFS(Graph * graph, int vertice){
    clean_visits(graph);
    sub_dfs(graph, vertice);
}


void sub_dfs(Graph *graph, int vertice){
    graph->visited[vertice] = true;
    printf("%d\n", vertice);

    for (Adj *curr = graph->vertices[vertice]; curr != NULL; curr = curr->next){
        if (!graph->visited[curr->item]){
            sub_dfs(graph, curr->item);  
        } 
    }
}


void mat_from_file(const char * path){
    FILE * f = fopen(path, "r");
    if(f == NULL){
        printf("Arquivo inexistente\n");
        exit(-1);
    }
    
    int size;
    fscanf(f, "%d", &size);
    int mat[size][size];

    for (int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            fscanf(f, "%d", &mat[i][j]);
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}


Graph * graph_from_file(const char * path){
    FILE * f = fopen(path, "r");
    if(f == NULL){
        printf("Arquivo inexistente\n");
        exit(-1);
    }
    
    int size;
    fscanf(f, "%d", &size);
    Graph * g = create_graph(size);

    for (int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int valor;
            fscanf(f, "%d", &valor);
            if(valor == 1){
                add_edge(g, i, j, 0);
            }
        }
    }
    return g;   
}


Graph* create_graph(int quantityNodes){
    Graph *temp = (Graph*) malloc(sizeof(Graph));
    temp->size = quantityNodes;
    temp->vertices = (Adj**) malloc(quantityNodes * sizeof(Adj*));
    temp->visited = (bool*) malloc(quantityNodes * sizeof(bool));
    int i;
    for (i = 0; i < quantityNodes; i ++){
        temp->vertices[i] = NULL;
        temp->visited[i] = false;
    }
    return(temp);

}


Adj* new_adj_list(int vertex, int weight){
    Adj *temp = (Adj*) malloc(1 * sizeof(Adj));
    temp->item = vertex;
    temp->next = NULL;
    temp->weight = weight;
    return(temp);
}


void add_edge(Graph *graph, int startVertex, int endVertex, int weight){
    Adj *vertex = new_adj_list(endVertex, weight);
    vertex->next = graph->vertices[startVertex];
    graph->vertices[startVertex] = vertex;

    //Undirected graph has an Edge to the other direction as well.
    /*vertex = new_adj_list(startVertex);
    vertex->next = graph->vertices[endVertex];
    graph->vertices[endVertex] = vertex;*/
}

void print_graph(Graph *graph){
    if (graph == NULL) return;

    printf("Graph (%d nodes):\n", graph->size);
    int i;
    for (i = 0; i < graph->size; i ++){
        printf("%d ~>", i);
        Adj *curr = graph->vertices[i];
        while (curr != NULL){
            printf(" %d - Weight: {%d} - ", curr->item, curr->weight);
            curr = curr->next;
        } 
          printf("\n");
    }
}

void clean_visits(Graph *graph){
    int i;
    for (i = 0; i < graph->size; i ++)
        graph->visited[i] = false;
}



void destroy_graph(Graph *graph){
    int i;
    for (i = 0; i < graph->size; i ++){
        Adj *curr = graph->vertices[i];
        while (curr != NULL)
        {
        graph->vertices[i] = graph->vertices[i]->next;
        free(curr);
        curr = graph->vertices[i];
        }
        free(curr);
        free(graph->vertices[i]);
    }
    free(graph->vertices);
    free(graph->visited);
    free(graph);
}


void print_matrix(int mat[][V]){
    printf("Graph (%d nodes):\n", V);

    for (int i = 1; i < V; i++){
        printf("%d ~>", i);
        for (int j = 1; j < V; j++){
            if(mat[i][j] > 0){
                printf(" %d - weight {%d} - " , j, mat[i][j]);
            }
        }
        printf("\n");
    }
}