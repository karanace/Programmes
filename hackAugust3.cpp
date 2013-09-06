#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
	int t;
	cin>>t;
	int n,k;
	for (int i = 0; i < t; ++i)
	{
		cin>>n>>k;
		vector<int> a(n);
		vector<int> b(n);
		for (int j = 0; j < n; ++j)
		{
			cin>>a[j];
		}
		for (int j = 0; j < n; ++j)
		{
			cin>>b[j];
		}

		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		do {
				int l;
				for (l = 0; l < n; ++l)
    			{
    				if(a[l] + b[l] <k)
    				break;
    			}
    			if(l==n)
    			{
    				cout<<"YES"<<endl;	
    				return 0;
    			}
    			
  			} while (next_permutation(a.begin(),a.end()));
  		cout<<"NO"<<endl;

	}
	return 0;
}
