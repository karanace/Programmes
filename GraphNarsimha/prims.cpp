#include "Graph.h"
#include <queue>
using namespace std;
#include <iostream>
#include<functional>
bool visited[100];
void prims(Graph *g,int u);
int main(int argc, char const *argv[])
{
	Graph *g = new Graph();
	//cout<<g->getV();
	prims(g,0);
	return 0;
}
void prims(Graph *g,int u)
{
	int distance[g->getV()];
	int through[g->getV()];
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater< pair<int,int> > > myQueue;
	queue <pair <int,int> > temp;
	int count=g->getV();
	pair<int,int> front;
	for (int i = 0; i < g->getV(); ++i)
	{
		distance[i] = -1;
	}
	distance[u] = 0;
	through[u] = u;
	myQueue.push(make_pair(distance[u],u));
	while(!myQueue.empty())
	{
		front = myQueue.top();
		myQueue.pop();
		visited[front.second] = true;
		count--;
		if(count==0)
			break;
		cout<<"Now : "<<front.second<<"\t"<<front.first<<endl;
		for (int i = 0; i < g->getV(); ++i)
		{
			if(!visited[i] && g->AdjMatrix[front.second][i] > 0)
			{
				if(distance[i] == -1)
				{
					distance[i] = g->AdjMatrix[front.second][i];
					through[i] = front.second;
					myQueue.push(make_pair(distance[i],i));

				}
				else
				{
					if(distance[i] > g->AdjMatrix[front.second][i])
					{
						distance[i] = g->AdjMatrix[front.second][i];
						through[i] = front.second;
						
						pair<int,int> x = myQueue.top();
						while(x.second !=i)
						{
							temp.push(x);
							myQueue.pop();
							x = myQueue.top();
						}
						if(x.second==i)
						x.first = distance[i];
						else
						x = make_pair(distance[i],i);
						myQueue.push(x);
						while(!temp.empty())	
						{
							myQueue.push(temp.front());
							temp.pop();
						}
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