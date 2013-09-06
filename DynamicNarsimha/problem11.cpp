#include <iostream>
using namespace std;
int maxSum(int *A,int n);
int main(int argc, char const *argv[])
{
	/* code */
	int a[] = {5,3,1,2,1A[2] + M[0]};
	cout<<maxSum(a,5)<<endl;
	return 0;
}
int maxSum(int *A,int n)
{
	int M[n+1];
	M[0] = A[0];
	M[1] = A[0] + A[1];
	M[2] = A[2] + M[0] > M[1] ? A[2] + M[0] : M[1];
 	for (int i = 3; i < n; ++i)

	{
		if(A[i] + A[i-1] + M[i-3] > A[i] + M[i-2])
		{
			if(A[i] + A[i-1] + M[i-3] > M[i-1])
			{
				M[i] = A[i] + A[i-1] + M[i-3];
			}
			else
			{
				M[i] = M[i-1]	;
			}
		}
		else
		{
			if(A[i] + M[i-2] > M[i-1])
			{
				M[i] = A[i] + M[i-2];
			}
			else
			{
				M[i] = M[i-1]	;
			}
		}
		
	}
	return M[n-1];
}