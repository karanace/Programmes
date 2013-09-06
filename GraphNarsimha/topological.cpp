#include "Graph.h"
#include <queue>
using namespace std;
#include <iostream>
bool visited[100];
void TopologicalSort(Graph *g);
int main(int argc, char const *argv[])
{
	Graph *g = new Graph();
	//cout<<g->getV();
	TopologicalSort(g);
	return 0;
}
void TopologicalSort(Graph *g)
{
	cout<<g->getV()<<endl;
	int indegree[g->getV()],front;
	queue<int> myQueue;
	for (int i = 0; i < g->getV(); ++i)
	{
		indegree[i] = 0;
	}
	for (int i = 0; i < g->getV(); ++i)
	{
		for (int j = 0; j < g->getV(); ++j)
		{
			if(g->AdjMatrix[i][j])
				indegree[j]++;
		}
	}
	for (int i = 0; i < g->getV(); ++i)
	{
		cout<<"indegree  of "<<i<<" : "<<indegree[i]<<endl;
	}
	//cout<<"indegree 3 :"<<indegree[3]<<endl;
	for (int i = 0; i < g->getV(); ++i)
	{
		if(indegree[i] == 0)
		myQueue.push(i);
	}
	while(!myQueue.empty())
	{
		front = myQueue.front();
		cout<<"Visited : "<<front<<endl;
		myQueue.pop();
		for (int j = 0; j < g->getV() ; ++j)
		{
			if(front !=j)
			{
				if(g->AdjMatrix[front][j])
				{
					indegree[j] = indegree[j] -1;
					if(indegree[j] ==0)
					myQueue.push(j);		
				}
				
			}
			
		}	
	}
}