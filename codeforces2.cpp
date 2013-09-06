#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,min,max;
	cin>>n;
	int x[n];
	int y[n]
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		cin>>b[i];	
	}
	vector <int> minIndex;
	vector <int> maxIndex;
	min1 = a[0];
	minIndex.push_back(0);
	for (int i = 1; i < n; ++i)
	{
		if(a[i] < min1)
		{
			min1 = i;
			minIndex.clear();
			minIndex.push_back(i);		
		}
		else if(a[i] == min1)
		{
			minIndex.push_back(i);
		}
		
	}
	max1 = a[0];
	for (int i = 0; i < n; ++i)
	{
		if(a[i] > max1)
		{
			max1 = i;
			maxIndex.clear();
			maxIndex.push_back(i);		
		}
		else if(a[i] == max1)
		{
			maxIndex.push_back(i);
		}
	}
	mylcm = LCM(x,y);
	
		for(int i = a;i<=b;)
		{
			if(i%mylcm == 0)
			{
				count++;
				i+=mylcm;
			}
			else
				i++;
		}
		cout<<count<<endl;
}
