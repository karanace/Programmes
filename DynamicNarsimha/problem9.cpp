#include <iostream>
using namespace std;
int maxSum(int *A,int n);
int main(int argc, char const *argv[])
{
	/* code */
	int a[] = {5,5,5,5,5};
	cout<<maxSum(a,5)<<endl;
	return 0;
}
int maxSum(int *A,int n)
{
	int M[n+1];
	M[0] = A[0];
	M[1] =(A[0] >A[1] ?A[0]:A[1]);
	for (int i = 2; i < n; ++i)
	{
		M[i] = M[i-2] + A[i] > M[i-1] ? M[i-2] + A[i] : M[i-1];
	}
	return M[n-1];
}