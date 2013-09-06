#include <iostream>
using namespace std;
void addFraction(int a[2],int b[2],int c[2]);
int LCM(int a,int b);
int GCD(int a,int b);
int main(int argc, char const *argv[])
{
	int a[2],b[2],c[2];
	cout<<"Enter numerator and denominator resp of num 1"<<endl;
	cin>>a[0]>>a[1];
	cout<<"Enter numerator and denominator resp num 1"<<endl;
	cin>>b[0]>>b[1];
	addFraction(a,b,c);
	if(c[1] !=1)
	cout<<"Addition is "<<c[0]<<"/"<<c[1]<<endl;
	else
	cout<<"Addition is "<<c[0]<<endl;
	return 0;
}
void addFraction(int a[2],int b[2],int c[2])
{
	int lcm;
	lcm = LCM(a[1],b[1]);
	cout<<"LCM of"<<a[1]<<" and "<<b[1] <<" is "<<lcm<<endl;
	a[0] = lcm/a[1] * a[0];
	b[0] = lcm/b[1] * b[0];
	a[1] = b[1] = lcm;
	c[0] = a[0] + b[0];
	c[1] = lcm;
	if(c[0] % c[1] == 0)
	{
		c[0] = c[0] /c[1];
		c[1] = 1;
	}
}
int LCM(int a,int b)
{
	int gcd = GCD(a,b); 
	cout<<"GCD of"<<a<<" and "<<b <<" is "<<gcd<<endl;
	return a*b /gcd;
}
int GCD(int a,int b)
{
	if(b ==0)
		return a;
	return GCD(b,a%b);
}