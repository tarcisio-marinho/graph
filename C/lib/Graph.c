
#include "Graph.h"



void BFS(Graph * graph, int vertice){
    if(graph == NULL)   return;

    int distancia[graph->size];
    int pai[graph->size];
    Queue q;

    create_queue(&q);
    clean_visits(graph);

    graph->visited[vertice] = true;
    enqueue(&q, vertice);

    while(!is_empty(q)){
        int valor = dequeue(&q);
        printf("%d ", valor);

        for(int i = 0; i < graph->size; i++){
            if(!graph->visited[i]){
                graph->visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
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

void raio(Graph * graph){
    int raio;
    int vertices = graph->size;
    int *distancias;
    int excentricidades[vertices];
    int maior = 0, menor;

    for(int i = 0; i < vertices; i++){
        distancias = DFS(graph, i);
        excentricidades[i] = distancias[vertices-1];
    }

    menor = excentricidades[0];
    for (int i = 0; i< vertices; i++){
        if(excentricidades[i] < menor){
            menor = excentricidades[i];
        }
    }
    raio = menor;
    

    printf("Raio: %d\n", raio);

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
                add_edge(g, i, j);
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


Adj* new_adj_list(int vertex){
    Adj *temp = (Adj*) malloc(1 * sizeof(Adj));
    temp->item = vertex;
    temp->next = NULL;
    return(temp);
}


void add_edge(Graph *graph, int startVertex, int endVertex){
    Adj *vertex = new_adj_list(endVertex);
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
            printf(" %d", curr->item);
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
