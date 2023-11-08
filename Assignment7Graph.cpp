/*Define a undirected graph with adjacent matrix
and adjacent list node.
Implement some basic operations about the graph*/

#include<iostream>

using namespace std;
const int MAX_SIZE = 50;
struct Graph{
    int vertices[MAX_SIZE];
    int adjmat[MAX_SIZE][MAX_SIZE];
    int size;  
};

Graph* graph(){
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->size = 0;

    for(int i = 0; i< MAX_SIZE; i++)
        for(int j = 0; j< MAX_SIZE; j++)
                graph->adjmat[i][j] = 0;

    return graph;
}

void addVertex(Graph* graph, int val){
    if(graph->size == MAX_SIZE)
        return;
    int n = graph->size;
    graph->vertices[n] = val;

    for(int i = 0; i <= n; i++){
        graph->adjmat[n][i] = 0;
        graph->adjmat[i][n] = 0;
        
    }
    graph->size++;
}

void removeVertex(Graph* graph, int index){
    if(index < 0 || index >= graph->size)
        return;
    for(int i = index; i < graph->size - 1; i++)
        graph->vertices[i] = graph->vertices[i+1];
    /*we need to assure that i+1 < graph-> size
    so that i < graph-> size - 1*/

    for(int i = index; i < graph->size - 1; i++){
        for(int j = 0; j < graph->size; j++)
            graph->adjmat[i][j] = graph->adjmat[i+1][j];
    }

    for(int i = 0; i < graph->size; i++){
        for(int j = index; j < graph->size - 1; j++)
            graph->adjmat[i][j] = graph->adjmat[i][j+1];
    }

    graph->size--;
}

void addEdge(Graph* graph, int i, int j){
    if(i < 0 || j < 0 || i >= graph->size || j >= graph->size || i == j)
        return;
    graph->adjmat[i][j] = 1;
    graph->adjmat[j][i] = 1;
}

void removeEdge(Graph* graph, int i, int j){
    if(i < 0 || j < 0 || i >= graph->size || j >= graph->size || i == j)
        return;
    graph->adjmat[i][j] = 0;
    graph->adjmat[j][i] = 0;
}

void print(Graph* graph){
    for(int i = 0; i< graph->size; i++){
        for(int j = 0; j < graph->size; j++)
            cout<<graph->adjmat[i][j]<<" ";
        cout<<endl;
    }

    cout<<graph->size;
}

int main(){
    Graph* g = graph();
    addVertex(g, 1);
    addVertex(g, 2);
    addVertex(g, 3);
    addVertex(g, 4);
    addVertex(g, 5);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);

    removeEdge(g, 0, 1);

    print(g);
    return 0;
}