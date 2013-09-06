#include "Graph.h"
#include <queue>
using namespace std;
#include <iostream>
bool visited[100];
void BFS(Graph *g,int u);
void BFSTraversal(Graph *g);
int main(int argc, char const *argv[])
{
	Graph *g = new Graph();
	//cout<<g->getV();
	BFSTraversal(g);
	return 0;
}
void BFS(Graph *g,int u)
{
	queue<int> myQueue;
	myQueue.push(u);
	while(!myQueue.empty())
	{
		int front = myQueue.front();
		myQueue.pop();
		visited[front] = true;
		cout<<"Visited :"<<front<<endl;
		for (int v = 0; v < g->getV(); ++v)
		{
			if(!visited[v] && g->AdjMatrix[u][v])
			{
				myQueue.push(v);
			}
		}	
	}
	
}
void BFSTraversal(Graph *g)
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
			BFS(g,v);
		}
	}
}