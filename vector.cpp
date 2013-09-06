#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	std::vector<int> v;
	int min=10000000;

	for(int i=0;i<5;i++)
	{
		if(a[i] <=min)
		{
			if(a[i] < min)
			{
				v.clear();
				v.push_back(i);
			}
			else
				v.push_back(i);	
			min = a[i];
		}
	}

	for(int i=0;i<v.size();i++)
	{
		cout<<v.at(i)<<endl;
	}
	return 0;
}
