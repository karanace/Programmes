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
	priority_queue<int> myQueue;
	int front;
	for (int i = 0; i < g->getV(); ++i)
	{
		distance[i] = -1;
	}
	distance[u] = 0;
	myQueue.push(u);
	while(!myQueue.empty())
	{
		front = myQueue.top();
		myQueue.pop();
		visited[u] = true;
		through[u] = u;
		for (int i = 0; i < g->getV(); ++i)
		{
			if(!visited[i] && g->AdjMatrix[front][i] > 0)
			{
				if(distance[i] == -1)
				{
					distance[i] = distance[front] + g->AdjMatrix[front][i];
					through[i] = front;
					myQueue.push(i);
				}
				else
				{
					if(distance[i] > distance[front] + g->AdjMatrix[front][i])
					{
						distance[i] = distance[front] + g->AdjMatrix[front][i];
						through[i] = front;
					}
				}
				
			}
		}
	}
	cout<<"Source :\t"<<u<<endl;
	cout<<"Destination\tDistance\tThrough"<<endl;
	for (int i = 0; i < g->getV(); ++i)
	{
		cout<<i<<"\t\t"<<distance[i]<<"\t\t"<<through[i]<<endl;
	}
}