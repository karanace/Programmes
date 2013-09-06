#include <iostream>
using namespace std;
int lenlongestCommonSubseqNaive(string a,string b,int m,int n);
int lenlongestCommonSubseqTabulated(string a,string b,int m,int n);
int main(int argc, char const *argv[])
{
	/* code */
	string me ="karanchugh",bro="pankajchugh"; 
	cout<<"Length of Longest Common Subsequence is\t"<<lenlongestCommonSubseqNaive(me,bro,me.size(),bro.size())<<endl;
	cout<<"Length of Longest Common Subsequence is\t"<<lenlongestCommonSubseqTabulated(me,bro,me.size(),bro.size())<<endl;
	return 0;
}
int lenlongestCommonSubseqNaive(string a,string b,int m,int n)
{
	if(m == 0 || n == 0)
		return 0;
	else
	{
		if(a[m-1] == b[n-1])
			return 1 + lenlongestCommonSubseqNaive(a,b,m-1,n-1);
		else
			return max(lenlongestCommonSubseqNaive(a,b,m-1,n),lenlongestCommonSubseqNaive(a,b,m,n-1));
	}
}
int lenlongestCommonSubseqTabulated(string a,string b,int m,int n)
{
	int LCS[m+1][n+1];
	for (int i = 0; i <=m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if(i==0 || j==0)
				LCS[i][j] = 0;
			else if(a[i-1] == b[j-1])
			{
				LCS[i][j] = LCS[i-1][j-1] +1;
			}
			else
				LCS[i][j] = max(LCS[i][j-1],LCS[i-1][j]);
		}	
	}
	return LCS[m][n];
}