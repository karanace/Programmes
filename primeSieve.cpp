#include <iostream>
#include<math.h>
using namespace std;
void prime(int n);
int main()
{
	prime(100000);
	return 0;
}
void prime(int n)
{
	short isPrime[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		isPrime[i] =1;
	}
	isPrime[0] = 0;
	isPrime[1] = 0;
	int m = sqrt(n);
	for (int i = 2;	i <=m ; ++i)
	{
		/* code */
		if(isPrime[i])
		{
			for(int k= i*i;k<=n;k+=i)
			{
				isPrime[k] = 0;
			}
		}
	}
	for (int i = 0; i < n+1; ++i)
		{
			if(isPrime[i] ==1)
				cout<<i <<"\t";
		}
		cout<<"are primes"<<endl;
}
