#include<string>
#include<iostream>
using namespace std;
void failureFunction(string pattern,int *f,int m)
{
	f[0] = f[1] = 0,x=1;
	for (int i = 2; i <=m; ++i)
	{
		/* code */
		j= f[i-1];
		while(x)
		{
			if(pattern[j] == pattern[i-1])
				{
					f[i] = j+1;
					break	;
				}
			if(j==0)
			{
				f[i] = 0;
				break;	
			}
			j = f[j]; 	
		}
		
	}

}