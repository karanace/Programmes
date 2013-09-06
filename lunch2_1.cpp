#include <iostream>
#include <algorithm>
using namespace std;
long long found =0;
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;

	int** data = new int*[n];
	for(int i = 0; i < n; ++i)
    data[i] = new int[m];
	//int data[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>data[i][j];
		}
	}
	long long sum =0;
	int hmax = min(n,m);
	int hmin = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for(int k = hmax; k>=hmin ; k--)
			{
				int count = 0;
				int flag =0;
				int nowAll=0;
				if(nowAll)
				{
					if(i+k<n && j+k<m)
					{
						found++;

					}
					else
						nowAll =0;
				}
				else
				{
				for(int x=i;x< i+k && x<n&&flag==0;x++)
				{
					for(int y=j;y<j+k && y<m &&flag==0;y++)	
					{
						if(y-j>=x-i)
						{
							if(data[x][y] == 1)
							{
								count++;
							}
							else
							{
								flag = 1;
							}
											
						}
					}
							
				}
				if(count >= (k*k - k)/2 + k )
					{
						
						found++;	
						nowAll =1;
					}
			}
					
					
			}
				
			}
		}	
	
	
			cout<<found<<endl;
	return 0;	
	}	


