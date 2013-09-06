#include <set>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
class AvoidRoads{

	public:
		unsigned long long numWays(int width,int height,vector<string> bad)
		{
			set< pair< pii , pii > > badEdges;
			unsigned long long data[width+1][height+1];
			for (int i = 0; i <= width; ++i)
			{
				for (int j = 0; j <= height; ++j)
				{
					data[i][j] = 0;
				}
			}
			data[0][0] =1;
			for (int i = 0; i < bad.size(); ++i)
			{
				string s = bad[i];
                istringstream is(s);
                pii ver1,ver2; 
                is>>ver1.first;
                is>>ver1.second; 
                is>>ver2.first;
                is>>ver2.second;
                badEdges.insert(make_pair(ver1,ver2));
                badEdges.insert(make_pair(ver2,ver1));
			}
			for (std::set<pair < pii,pii > >::iterator i = badEdges.begin(); i != badEdges.end(); ++i)
			{
				pair <pii,pii> p = *i;
				cout<<p.first.first<<" "<<p.first.second<<endl;
				cout<<p.second.first<<" "<<p.second.second<<endl;
			}
			for (int i = 1; i <= width; ++i)
			{
				if(badEdges.find(make_pair(make_pair(i-1,0),make_pair(i,0))) == badEdges.end())
				data[i][0] = data[i-1][0];
			}
			for (int i = 1; i <= height; ++i)
			{
				if(badEdges.find(make_pair(make_pair(0,i-1),make_pair(0,i))) == badEdges.end())
				data[0][i] = data[0][i-1];
			}

			
			for (int i = 1; i <= width; ++i)
			{
				for (int j = 1; j <= height; ++j)
				{
					if(badEdges.find(make_pair(make_pair(i-1,j),make_pair(i,j))) == badEdges.end())
					{
						data[i][j] += data[i-1][j];
						//cout<<i<<j<<" case 1"<<endl;	
					}
					
					if(badEdges.find(make_pair(make_pair(i,j-1),make_pair(i,j))) == badEdges.end())
					{
						data[i][j] += data[i][j-1];	
						//cout<<i<<j<<" case 2"<<endl;	
					}
					
				}
			}
			
	}
};
int main(int argc, char const *argv[])
{
	AvoidRoads ar;
	vector<string> x;
	//x.push_back("0 0 0 1");
	//x.push_back("6 6 5 6");
	//x.push_back("1 1 2 1");
	cout<<ar.numWays(35,31,x)<<endl;
	return 0;
}