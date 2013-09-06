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
	for (int i = 2; i <=n; ++i)
	{
		f[i] = 0;
		for (int j = 1; j < i; ++j)
		{
			f[i] += 2 * f[j] * f[j-1];
		}
	}
	return f[n];
}

