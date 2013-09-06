#include "Graph.h"
using namespace std;
#include <iostream>
bool visited[100];
void DFS(Graph *g,int u);
void DFSTraversal(Graph *g);
int main(int argc, char const *argv[])
{
	Graph *g = new Graph();
	//cout<<g->getV();
	DFSTraversal(g);
	return 0;
}
void DFS(Graph *g,int u)
{
	visited[u] = true;
	cout<<"Visited :"<<u<<endl;
	for (int v = 0; v < g->getV(); ++v)
	{
		if(!visited[v] && g->AdjMatrix[u][v])
		{
			DFS(g,v);
		}
	}
}
void DFSTraversal(Graph *g)
{
	cout<<g->getV()<<endl;
	for (int i = 0; i < g->getV(); ++i)
	{
		visited[i] = false;
	}
	for (int v = 0; v < g->getV(); ++v)
	{
		if(!visited[v])
		{
			DFS(g,v);
		}
	}
}