#include <iostream>
#include <vector>
using namespace std;
void mysort(vector<int> &data);
long long count =0;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<int> data(n);
	long long sum =0;
	for (int i = 0; i < n; ++i)
	{
		cin>>data[i];
	}
	mysort(data);
	cout<<count<<endl;
	
}
void mysort(vector<int> &data)
{
	if(data.size() == 1);
	else
	{
		vector<int> less;
		vector<int> greater;
		int middle = (data.size() + 1 )/2 - 1 ;
		
		int pivot = data[middle];
		

		for (int i = 0; i < data.size(); ++i)
		{
			if(data[i] < pivot)
			less.push_back(data[i]);
			else if(data[i] > pivot)	
			greater.push_back(data[i]);
		}
		count +=data.size();
		if(!less.empty())
		mysort(less);
		if(!greater.empty())
		mysort(greater);
	}
	

}