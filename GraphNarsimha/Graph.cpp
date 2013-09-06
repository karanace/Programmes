#include "Graph.h"
#include <iostream>
#include <utility>
using namespace std;
void Graph::createGraph(int matOrList,int directedOrUndirected,int weightedOrUnweighted)
{
		int v,e;
		cout<<"Enter Num Of Vertices and Edges respectivally"<<endl;
		cin>>v>>e;
		setV(v);
		setE(e);
		if(matOrList==1)
		{
			AdjMatrix = new int*[v];	//Array of Rows
			for(int i = 0; i < v; ++i)
	    		AdjMatrix[i] = new int[v];	//Ith row in an array
			for (int i = 0; i < getV(); ++i)
			{
				for (int j = 0; j <getV(); ++j)
				{
					AdjMatrix[i][j] = 0;	//Initially no edge between any vertices
				}
			}
			for (int i = 0; i < getE(); ++i)
			{
				int u,v,w;
				if(weightedOrUnweighted==1)
				{
					cout<<"Enter Source, Destination Vertex and weight respectivally"<<endl;	
					cin>>u>>v>>w;
				}
				else
				{
					cout<<"Enter Source and Destination Vertex resp"<<endl;
					cin>>u>>v;
					w=1;
				}
				AdjMatrix[u][v] = w;
				if(directedOrUndirected ==2)
				AdjMatrix[v][u] = w;	//If undirected AdjMatrix[u][v] = AdjMatrix[v][u] i.e symettric			
			}	
		}
		else
		{
			//AdjList = new forward_list<forward_list <int> >;	//Array of Rows
			AdjList = new forward_list<pair<int,int> >[getV()];
			for (int i = 0; i < getE(); ++i)
			{
				int u,v,w;
				if(weightedOrUnweighted==1)
				{
					cout<<"Enter Source, Destination Vertex and weight respectivally"<<endl;	
					cin>>u>>v>>w;
				}
				else
				{
					cout<<"Enter Source and Destination Vertex resp"<<endl;
					cin>>u>>v;
					w=1;
				}
				AdjList[u].push_front(make_pair(v,w));
				if(directedOrUndirected ==2)
				AdjList[v].push_front(make_pair(u,w));	//If undirected AdjMatrix[u][v] = AdjMatrix[v][u] i.e symettric
			}		
		}

	}
		
Graph::Graph()
{
		int matOrList,directedOrUndirected,weightedOrUnweighted;
		cout<<"Enter 1 for Adjacency Matrix Representation"<<endl;
		cout<<"Enter 2 for Adjacency List Representation"<<endl;
		cin>>matOrList;
		cout<<"Enter 1 for Directed Graph"<<endl;
		cout<<"Enter 2 for Un-directed Graph"<<endl;
		cin>>directedOrUndirected;
		cout<<"Enter 1 for Weighted Graph"<<endl;
		cout<<"Enter 2 for Unweighted Graph"<<endl;
		cin>>weightedOrUnweighted;
		createGraph(matOrList,directedOrUndirected,weightedOrUnweighted);
}
Graph::~Graph()
{

}
