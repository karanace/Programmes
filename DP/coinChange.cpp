using namespace std;
#include <iostream>
#include <vector>
int coinChangeRecursive(vector<int> &s,int m,int sum);
int coinChangeDP(vector<int> &s,int m,int sum);
int main(int argc, char const *argv[])
{
	int a[] = {2,5};
	vector<int> coins(a,a+2);
	cout<<coinChangeRecursive(coins,2,10)<<endl;
	cout<<coinChangeDP(coins,2,10)<<endl;
	
	return 0;
}
int coinChangeRecursive(vector<int> &s,int m,int sum)
{
	if(sum==0)	//only 1 solution do not include any coin
		return 1;
	if(sum<0)	//No solution
		return 0;
	if(m<=0 &sum>=1)	//No solution
		return 0;
	return coinChangeRecursive(s,m-1,sum) + coinChangeRecursive(s,m,sum - s[m-1]);
}
int coinChangeDP(vector<int> &s,int m,int sum)
{
	int Lookup[sum + 1][m]; //One extra row for sum 0
	for (int i = 0; i < m; ++i)
	Lookup[0][i] = 1;
	int x,y;
	for (int i = 1; i < sum+1; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			x = i-s[j] >=0 ? Lookup[i-s[j]][j]:0;
			y = j>=1 ? Lookup[i][j-1] : 0;

			Lookup[i][j] = x + y;	
		}
	}
	return Lookup[sum][m-1];
}
