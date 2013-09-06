using namespace std;
#include <iostream>
int editDistance(string a,string b);
int main(int argc, char const *argv[])
{
	string a = "sunday",b = "sunday";
	cout<<"Editing Cost\t"<<editDistance(a,b)<<endl; 
	return 0;
}
int editDistance(string a,string b)
{
	int m = a.size();
	int n = b.size();
	int edit[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		edit[i][0] = i;
	}
	for(int i=0;i<=n;i++)
	{
		edit[0][i] = i;
	}
	int left,down,corner;
	for (int i = 1; i <=m; ++i)	//Assuming string 'a' starts at 1
	{
		for (int j = 1; j <=n; ++j)//Assuming string 'b' starts at index 1
		{
			left = edit[i-1][j] + 1;
			down = edit[i][j-1] + 1;
			if(a.at(i-1) != b.at(j-1))//Adjusting to get actual 0 based index 
			{
				corner = 2 + edit[i-1][j-1];
				cout<<a.at(i-1)<<" and "<<b.at(j-1)<<endl;	
			}
			else
			corner = edit[i-1][j-1];
			edit[i][j] = min(min(left,down),corner);
		}
	}

	for (int i = 0; i <=m; ++i)
	{
		for (int j = 0; j <=n; ++j)
		{
			cout<<edit[i][j]<<"\t";
		}
		cout<<endl;
	}

	return edit[m][n];
}