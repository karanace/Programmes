#include <iostream>
#include <bitset>

using namespace std;
bitset<2000000000> resultA;

int main(int argc, char const *argv[])
{
	unsigned long long x,y,a,b,mylcm,count=0;
	cin>>x>>y>>a>>b;
	for(int i = 0;i<=b;i++)
	{
		resultA[i] = 0;
	}
	for(int i = x;i<=b;i+=x)
	{
		resultA[i]  = 1;
	}
	for(int i = y;i<=b;i++)
	{
		if(i%y ==0)
		{
		if(resultA[i] == 1);
		else
		resultA[i]  = 0;		
		}
		else if(resultA[i] == 1)
		resultA[i] = 0;
	}
	for(int i = a;i<=b;i++)
	{
		if(resultA[i] == 1)
		{
			count++;
		}
	}
	cout<<count;
	
}
