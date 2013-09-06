#include <iostream>
using namespace std;
int CatalanNum(int n);
int main(int argc, char const *argv[])
{
	/* code */
	cout<<CatalanNum(3)<<endl;
	return 0;
}
int CatalanNum(int n)
{
	if(n==0)
		return 1;
	int count = 0;
	for (int i = 1; i <=n; ++i)
	{
		count+= CatalanNum(i-1)*CatalanNum(n-i);
	}
	return count;
}