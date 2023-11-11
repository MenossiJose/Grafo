#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	void addEdge(int v, int w);
	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{

	adj[v].push_back(w);
}

void Graph::DFS(int v)
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}


int main()
{

	Graph g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 9);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(4, 6);
	g.addEdge(4, 7);
	g.addEdge(5, 6);
	g.addEdge(7, 8);
	g.addEdge(7, 9);

	cout << "Busca em profundida no grafo"
			" Começando do vértice 0 \n";

	g.DFS(0);

	return 0;
}


