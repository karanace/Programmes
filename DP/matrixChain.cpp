using namespace std;
#include <iostream>
#include <vector>
#include <limits>
int matrixChain(vector<int> &p);
int main(int argc, char const *argv[])
{
	int a[] = {40,20,30,10,30};
	vector<int> dim(a,a+5);
	cout<<matrixChain(dim)<<endl;
	return 0;
}
int matrixChain(vector<int> &p)
{
	int n = p.size();
	int Lookup[n][n];

	/*
	*	m[i][j] = Min num of mul required to mul A[i]A[i+1]...............A[j-1]A[j]
		Where p[i-1] * p[i] is dimension of ith matrix
		for ex 1st matrix dimensions are p[0] * p[1]
	*/
			for (int i = 1; i < n; ++i)
			{
				Lookup[i][i] = 0;
			}

		int L,j,cost;		//L is chain length

		for (L = 2; L < n; ++L)
		{
			for (int i = 1; i <= n-L+1; ++i)
			{
				/* code */
				j = i + L - 1;
				Lookup[i][j] = numeric_limits<int>::max();
				for (int k = i; k <=j-1; ++k)
				{
					/* code */
					cost = Lookup[i][k] + Lookup[k+1][j] + p[i-1]*p[k]*p[j];
					if(cost<Lookup[i][j])
						Lookup[i][j] = cost;
				}
			}
		}
		return Lookup[1][n-1];
}
