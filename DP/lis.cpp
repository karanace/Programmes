#include <iostream>
using namespace std;
int lenlongestNonDecreasingSubseq(int *a,int n);
int main(int argc, char const *argv[])
{
	/* code */
	int a[] ={10,9,10,9,10,9,10,9};
	cout<<"Length of Longest non decreasing subsequence is\t"<<lenlongestNonDecreasingSubseq(a,8)<<endl;
	return 0;
}
int lenlongestNonDecreasingSubseq(int *a,int n)
{
	int Lookup[n];
	for (int i = 0; i < n; ++i)
	{
		Lookup[i] = 1;
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if(a[j] <= a[i] && Lookup[i] < Lookup[j] +1 )
			{
				Lookup[i] = Lookup[j] +1;	
			}
		}
	}
	int maxElement = Lookup[0];
	for (int i = 1; i < n; ++i)
	{
		if(Lookup[i] > maxElement)
			maxElement = Lookup[i];
	}
	return maxElement;
}
