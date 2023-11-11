#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_VERTICES 50

typedef struct Graph_t {
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;
 
Graph* Graph_create(int V)
{
    Graph* g = malloc(sizeof(Graph));
    g->V = V;
    int i;
    int j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            g->adj[i][j] = false;
        }
    }
 
    return g;
}
 
void Graph_destroy(Graph* g) { free(g); }
 
void Graph_addEdge(Graph* g, int v, int w)
{
    g->adj[v][w] = true;
}
 
void Graph_BFS(Graph* g, int s)
{
    bool visited[MAX_VERTICES];
    int i;
    for (i = 0; i < g->V; i++) {
        visited[i] = false;
    }
 
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
 
    visited[s] = true;
    queue[rear++] = s;
 
    while (front != rear) {
 
        s = queue[front++];
        printf("%d ", s);
        int adjacent;

        for (adjacent = 0; adjacent < g->V;
             adjacent++) {
            if (g->adj[s][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}
 
int main(){

    Graph* g = Graph_create(15);
    Graph_addEdge(g, 0, 1);
    Graph_addEdge(g, 0, 2);
    Graph_addEdge(g, 1, 3);
    Graph_addEdge(g, 1, 4);
    Graph_addEdge(g, 1, 5);
    Graph_addEdge(g, 3, 6);
    Graph_addEdge(g, 3, 7);
    Graph_addEdge(g, 5, 8);
    Graph_addEdge(g, 5, 9);
    Graph_addEdge(g, 7, 10);
    Graph_addEdge(g, 7, 11);
    Graph_addEdge(g, 7, 12);
    Graph_addEdge(g, 9, 13);
    Graph_addEdge(g, 9, 14);
 
    printf("Rastreamento de busca em largura "
           "Comecando do vertice 1 \n");
    Graph_BFS(g, 1);
    Graph_destroy(g);
 
    return 0;
}