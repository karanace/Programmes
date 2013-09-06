#include <string>
#include <iostream>
using namespace std;

class GooseTattarrattatDiv2
{
	public :
	int a[26];
	int getmin(string S)
	{
			for(int i=0;i<26;i++)
			{
				a[i] = -1;
			}
		int len = S.size();
		cout<<"length is "<<len<<endl;
		for(int i=0;i<len;i++)
		{
				if(a[S[i] - 'a'] == -1)
				{
					a[S[i] -  'a']  = a[S[i] -  'a'] + 2;
					cout<<S[i]<<endl;
					
				}
				else
				{
					a[S[i] -  'a'] = a[S[i] -  'a'] + 1;
					
				}
		}
		cout<<a[4]<<endl;
		int maxVal = getMax(a);
		cout<<"max val "<<maxVal<<endl;
		int ans = len- maxVal;
		cout<<"ans is "<<ans<<endl;
		return ans;
	}
	int getMax(int a[26])
	{
		int myMax = 0;
		for (int i = 1; i < 26; ++i)
		{
			if(a[i] > a[myMax])
			{
				myMax = i;
			}
		}
		return a[myMax];
	}
	
	
};
int main()
	{
		string s = "geese";
		GooseTattarrattatDiv2 g;
		cout<<g.getmin(s)<<endl;
	}