using namespace std;
#include <iostream>
#include <vector>
class Disjoint
{
	public:
	Disjoint();
	Disjoint(int numEle);
	int myUnion(int s1,int s2);
	int find(int element);
	void print();
	
	protected:
		vector<int> links;
		vector<int> ranks;
};
