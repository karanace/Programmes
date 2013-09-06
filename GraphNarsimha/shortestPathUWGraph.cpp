#include "Graph.h"
#include <queue>
using namespace std;
#include <iostream>
bool visited[100];
void shortestPath(Graph *g,int u);
int main(int argc, char const *argv[])
{
	Graph *g = new Graph();
	//cout<<g->getV();
	shortestPath(g,0);
	return 0;
}
void shortestPath(Graph *g,int u)
{
	int distance[g->getV()];
	int through[g->getV()];
	int front;
	queue<int> myQueue;
	myQueue.push(u);
	for (int i = 0; i < g->getV(); ++i)
	{
		distance[i] = -1;
		visited[i] = false;
	}
	distance[u] = 0;
	visited[u] = true;
	while(!myQueue.empty())
	{
		front = myQueue.front();
		myQueue.pop();
		for (int i = 0; i < g->getV(); ++i)
		{
			if(visited[i] == false && g->AdjMatrix[front][i])
			{
				if(distance[i] == -1)
				{
					distance[i] = distance[front] + 1;
					through[i] = front;
					myQueue.push(i);
				}
					
			}
		}
	}
	for (int i = 0; i < g->getV(); ++i)
	{
		cout<<"Distance "<<u<<" : "<<i<<"\t--->\t"<<distance[i]<<endl;
	}
}