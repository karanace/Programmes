#include<iostream>
#include<math.h>
using namespace std;
int gcdEuclid(int,int);
int LCM(int,int);
int main()
{
	int a,b,lcm;
	cout<<"Enter a and b"<<endl;
	cin>>a>>b;
	lcm = LCM(a,b);
	cout<<"GCD of "<<a <<" and "<<b<<" is "<<lcm<<endl;
	return 0;
}
int gcdEuclid(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcdEuclid(b,a%b);
}
int LCM(int a,int b)
{
	return b*a/gcdEuclid(a,b);
}