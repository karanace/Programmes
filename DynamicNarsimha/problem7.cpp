/*
* MAX VALUE CONTIGUOUS SEQUENCE Without Dynamic

*/
#include <iostream>
using namespace std;
int maxValueSeq(const int *a,int n);
int maximumValue(int *array,int n);
int main(int argc, char const *argv[])
{
	/* code */
	int a[6] = {-2,11,-4,13,-5,2};
	cout<<maxValueSeq(a,6)<<endl;	
	return 0;
}
int maxValueSeq(const int *a,int n)
{
	int sumEndingHere =0 ,sumSoFar =0;
	for (int i = 0; i < n; ++i)
	{
		sumEndingHere+=a[i];
		if(sumEndingHere<0)
		{
			sumEndingHere = 0;
			continue;
		}
		if(sumEndingHere >sumSoFar)
		{
			sumSoFar = sumEndingHere;
		}
	}
	return sumSoFar;
}

