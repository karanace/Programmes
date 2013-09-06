#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef	pair<int,int> pii;
typedef	pair<int,char> pic;
typedef	pair< int,pair<int,int> > pipii;  
typedef queue<int> qi;


int main()
{
	set<int> s;
	for (int i = 0; i < 50; ++i)
	{
		s.insert(i*i);
	}
	s.erase(s.find(1));
	
}
