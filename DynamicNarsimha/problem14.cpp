#include <iostream>
using namespace std;
unsigned long long CatalanNum(int n);
unsigned long long Cat[1024];
int main(int argc, char const *argv[])
{
	/* code */
	for (int i = 0; i < 1024; ++i)
	{
		Cat[i] = -100 ;
	}
	Cat[0] = 1;
	cout<<CatalanNum(30)<<endl;
	return 0;
}
unsigned long long CatalanNum(int n)
{
	if(Cat[n] !=-100)
		return Cat[n];
	Cat[n] = 0;
	for (int i = 1; i <=n; ++i)
	{
		Cat[n] +=CatalanNum(i-1) * CatalanNum(n-i);
	}
	return Cat[n];

}