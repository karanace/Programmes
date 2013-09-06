#include<iostream>
#include<math.h>
using namespace std;
int gcdEuclid(int,int);
int main()
{
	int a,b,gcd;
	cout<<"Enter a and b"<<endl;
	cin>>a>>b;
	gcd = gcdEuclid(a,b);
	cout<<"GCD of "<<a <<" and "<<b<<" is "<<gcd<<endl;
	return 0;
}
int gcdEuclid(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcdEuclid(b,a%b);
}