/*
* Recurance Problem
*/
#include <iostream>
using namespace std;
int func(int n);
int f[100];
int main(int argc, char const *argv[])
{
	/* code */
	cout<<func(3)<<endl;
	
	return 0;
}
int func(int n)
{
	f[0] = f[1] = 2;
	f[2] = 2* f[1] * f[0];
	for (int i = 3; i <=n; ++i)
	{
		f[i] = f[i-1] + 2*f[i-1]*f[i-2];
	}
	return f[n];
}

