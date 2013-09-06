/*
	*Aim :	Calculate Binomial Coefficient nCk using Dynamic programming 
*/
#include <iostream>
#include <vector>
using namespace std;
#define	PB	push_back
typedef unsigned long long ull;
typedef vector<int> vi;
using namespace std;
ull knapsack(vi &values,vi &weights,ull w);
int main(int argc, char const *argv[])
{
	/* code */
	int n,temp;
	ull w;
	cout<<"Enter No of items"<<endl;
	cin>>n;
	cout<<"Total Capacity"<<endl;
	cin>>w;
	vi values;
	vi weights;
	cout<<"Enter Value and weight resp for "<<n<<" items"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		values.PB(temp);
		cin>>temp;
		weights.PB(temp);
	}
	cout<<"Max Profit : "<<knapsack(values,weights,w)<<endl;
	return 0;
}
ull knapsack(vi &values,vi &weights,ull totalCap)
{
	ull Lookup[values.size()][weights.size()];
	for (int i = 0; i <= values.size(); ++i)
	{
		for (int w = 0; w <= totalCap; ++w)
		{
				if(i==0 || w==0)
					Lookup[i][w] = 0;
				else if(weights[i-1]<=w)
					Lookup[i][w] = max(values[i-1] + Lookup[i-1][w-weights[i-1]],Lookup[i-1][w]);
				else
					Lookup[i][w] = Lookup[i-1][w];
		}		
	}

	return Lookup[values.size()][totalCap];
}