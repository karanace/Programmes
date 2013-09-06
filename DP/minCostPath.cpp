using namespace std;
#include <iostream>
#include <vector>
typedef  vector<int>  vi;
typedef vector< vi > vvi;
int minCostPath(vvi &cost,int x,int y,int m,int n);
int main(int argc, char const *argv[])
{
	vvi x(3,vi(3));
	for (int i = 0; i <3 ; ++i)
	{
		for (int j = 0; j <3; ++j)
		{
			x[i][j] = 100;
		}
	}
	x[0][1]= 1;
	x[0][2]= 2;
	x[1][2] = 4;

	for (int i = 0; i <3 ; ++i)
	{
		for (int j = 0; j <3; ++j)
		{
			cout<<x[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<minCostPath(x,3,3,2,2)<<endl;
	
	return 0;
}
int minCostPath(vvi &cost,int x,int y,int m,int n)
{
	int myCost[x][y],left,up,corner;
	myCost[0][0] = cost[0][0];
	for (int i = 1; i <x ; ++i)
	{
		myCost[i][0] = myCost[i-1][0] + cost[i][0];
	}
	for (int i = 1; i <y ; ++i)
	{
		myCost[0][i] = myCost[0][i-1] + cost[0][i];
	}
	
	for (int i = 1; i <=m ; ++i)
	{
		for (int j = 1; j <=n; ++j)
		{
			left = myCost[i-1][j] + cost[i][j];
			up = myCost[i][j-1] + cost[i][j]; 
			corner = myCost[i-1][j-1] + cost[i][j];
			myCost[i][j] = min(min(left,up),corner);
		}
	}
	return myCost[m][n];
}
