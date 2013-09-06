#include <forward_list>
#include <utility>
using namespace std;
class Graph
{
	int V;
	int E;	
	void createGraph(int matOrList,int directedOrUndirected,int weightedOrUnweighted);
public:
	//Graph(int directedOrUndirected,int matOrList);
	Graph();
	~Graph();
	int **AdjMatrix;
	forward_list<pair<int,int>>  *AdjList;
	void setV(int v)
	{
		V = v;
	}
	void setE(int e)
	{
		E = e ;
	}
	int getV()
	{
		return V;
	}
	int getE()
	{
		return E;
	}
	/* data */
};