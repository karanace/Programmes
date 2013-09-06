#include <iostream>
#include <algorithm>
#include <vector>
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
		sort(b.rbegin(),b.rend());
		for (int p = 0; p < n; ++p)
		{
			if(a[p] + b[p] < k)
			break;
		}
		if(p==n)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}
	return 0;
}
