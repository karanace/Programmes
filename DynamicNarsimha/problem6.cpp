/*
* MAX VALUE CONTIGUOUS SEQUENCE Dynamic 1

*/
#include <iostream>
using namespace std;
int maxValueSeq(const int *a,int *,int n);
int maximumValue(int *array,int n);
int main(int argc, char const *argv[])
{
	/* code */
	int a[6] = {-2,11,-4,13,-5,2};
	int m[6];
	cout<<maxValueSeq(a,m,6)<<endl;	
	return 0;
}
int maxValueSeq(const int *a,int *m,int n)
{
	int maxSum = 0;
	m[n] = 0;
	if(a[0] >0)
		m[0] = a[0];
	else
		m[0] = 0;

	for (int i = 1; i < n; ++i)
	{
		if(m[i-1] + a[i] > 0)
			m[i] = m[i-1] + a[i];
		else
			m[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cout<<m[i]<<endl;
	}
	for (int i = 0; i < n; ++i)
	{
		if(m[i] >maxSum)
			maxSum = m[i];
	}
	return maxSum;
}

