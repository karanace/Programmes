#include <iostream>
#include <vector>
#include <limits>
using namespace std;
int minJumps(int *data,int n);
int main(int argc, char const *argv[])
{
	/* code */
	int x[] = {1, 3, 0, 0, 1, 2, 1, 2, 0, 1, 0};
	cout<<"min Jumps required are\t"<<minJumps(x,11)<<endl;
	return 0;
}
int minJumps(int *data,int n)
{
	if(n ==0 || data[0] ==0)
		return numeric_limits<int>::max();
	int numJump[n];
	for (int i = 0; i < n; ++i)
	{
		numJump[i] = numeric_limits<int>::max();
	}
	numJump[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if(i<= j + data[j] && numJump[j] !=numeric_limits<int>::max() )
			{
				numJump[i] = numJump[j] + 1;
				break;
			}
		}
	}
	return numJump[n-1];
}
