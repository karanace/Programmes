#include <iostream>
#include<math.h>
using namespace std;
int gcdNaive(int,int);
int main(int argc, char const *argv[])
{
	int a,b,gcd;
	cout<<"Enter a and b"<<endl;
	cin>>a>>b;
	gcd = gcdNaive(a,b);
	cout<<"GCD of "<<a <<" and "<<b<<" is "<<gcd<<endl;
	return 0;
}
int gcdNaive(int a,int b)
{
	for(int i= min(a,b);i>=1;i--)
	{
		if(a%i==0 && b%i==0)
			return i;
	}
}