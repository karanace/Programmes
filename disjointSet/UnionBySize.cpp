#include "disjointSet.h"
#include <vector>
using namespace std;
Disjoint::Disjoint(int numEle)
{
	links.resize(numEle,-1);
	ranks.resize(numEle,1);
}
int Disjoint::myUnion(int s1,int s2)
{
	int parent,child;
	if(links[s1] != -1 || links[s2] != -1)
	{
		cerr<<"Must call union on set, not on individual elements"<<endl;
	}
	if(ranks[s1] >ranks[s2])
	{
		parent = s1;
		child = s2;
	}
	else
	{
		parent = s2;
		child = s1;
	}
	links[child] = parent;
	if(ranks[s1] == ranks[s2])
		ranks[parent]++;
	return parent;
}
int Disjoint::find(int element)
{
	while(links[element] != -1)
	{
		element = links[element];
	}
	return element;
}
void Disjoint::print()
{
	int i;
  	cout<<endl;
  	cout<<"Elts: ";
  	for (i = 0; i < links.size(); i++)
  	cout<<" "<<i;
  	cout<<endl;
  	cout<<"Links:";
  	for (i = 0; i < links.size(); i++)
  	cout<<" "<<links[i];
  	cout<<endl;
  	cout<<"Ranks:";
  	for (i = 0; i < links.size(); i++)
  	cout<<" "<<ranks[i];
  	cout<<endl;
}