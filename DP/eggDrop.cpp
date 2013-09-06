/*
	*Aim :	Calculate Binomial Coefficient nCk using Dynamic programming 
*/
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
#define	PB	push_back
typedef unsigned long long ull;
typedef vector<int> vi;
using namespace std;
int eggDrop(int numFloor,int numEgg);
int main(int argc, char const *argv[])
{
	/* code */
	int numFloor,numEgg;
	cout<<"Enter No of Floors and Eggs resp"<<endl;
	cin>>numFloor>>numEgg;
	cout<<"Min Trials in Worst Case: "<<eggDrop(numFloor,numEgg)<<endl;
	return 0;
}
int eggDrop(int numFloor,int numEgg)
{
	int Lookup[numEgg+1][numFloor+1],res,x;
	/*If numFloor ==0 No eggs Needed, if numFloor ==1 Only 1 egg needed	*/
	for (int i = 1; i <=numEgg; ++i)
	{
		Lookup[i][0] = 0;
		Lookup[i][1] = 1;
	}
	/*If only 1 egg is given in worst case we need numFloor Trials 	*/
	for (int i = 1; i <=numFloor; ++i)
	{
		Lookup[1][i] = i;
	}
	for (int i = 2; i <=numEgg; ++i)
	{
		for (int j = 2; j <=numFloor; ++j)
		{
			Lookup[i][j] = numeric_limits<int>::max();
			for (x  = 1; x <=j; ++x)
			{
				res = 1 + max(Lookup[i-1][x-1],Lookup[i][j-x]);
				if(res < Lookup[i][j])
					Lookup[i][j] = res;
			}
		}
	}
	return Lookup[numEgg][numFloor];
}