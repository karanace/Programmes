/*
	*Aim :	Calculate Binomial Coefficient nCk using Dynamic programming 
*/
#include <iostream>
#include <limits>
typedef unsigned long long ull;
using namespace std;
ull binCoef(int n,int k);
int main(int argc, char const *argv[])
{
	/* code */
	int n,k;
	cout<<"Enter n and k respectivally"<<endl;
	cin>>n>>k;
	cout<<"Binomial Coefficient :"<<n<<"C"<<k<<" = "<<binCoef(n,k)<<endl;
	return 0;
}
ull binCoef(int n,int k)
{
	ull Lookup[n+1][k+1];
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <=k ; ++j)
		{
			if(j==0 || i==j)
			Lookup[i][j] = 1;
			else if(j>i)
			Lookup[i][j] = 0;
			else
			{
				Lookup[i][j] = Lookup[i-1][j-1]+ Lookup[i-1][j];
			}

		}	
	}
	return Lookup[n][k];
}