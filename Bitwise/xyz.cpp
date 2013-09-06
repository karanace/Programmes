#include <iostream>
#include <bitset>
using namespace std;
int main(int argc, char const *argv[])
{
	bitset<32> a,b;
	for (int i = 0; i < 32; ++i)
	{
		b[i] = 1;
		a[i] = 1;
	}
	long x = b.to_ulong();
	cout<<x;
	return 0;
}