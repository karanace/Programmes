/*
* MAX VALUE CONTIGUOUS SEQUENCE
*/
#include <iostream>
using namespace std;
int maxValueSeq(const int *a,int n);
int maximumValue(int *array,int n);
int main(int argc, char const *argv[])
{
	/* code */
	int a[6] = {1,-3,4,-2,-1,6};
	cout<<maxValueSeq(a,6)<<endl;	
	return 0;
}
int maxValueSeq(const int *a,int n)
{
	int maxSum = 0;
	for (int i = 0; i < n; ++i)
	{
		int currentSum = 0;
		for (int j = i; j < n; ++j)
		{
			currentSum += a[j];
			if(currentSum > maxSum)
				maxSum = currentSum;
		}
	}
	return maxSum;
}

