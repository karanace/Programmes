using namespace std;
#include <iostream>
int main(int argc, char const *argv[])
{
	int t;
	int num;
	cin>>t;
	int* a[t];
	int size[t];
	for (int i = 0; i < t; ++i)
	{
		int num;
		cin>>num;
		a[i] = new int[num];
		size[i] = num;
		for (int j = 0; j < num; ++j)
		{
			cin>>a[i][j];
		}
	}

	for (int i = 0; i < t; ++i)
	{
		for (int j = 0; j < size[i]; ++j)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
}