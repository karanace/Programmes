#include <iostream>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	int t;
	set<char> s;
	string keyword,data;
	cin >>t;
	cin.ignore('\n',255);
	for(int i=0;i<t;i++)
	{
		getline(cin,keyword);
		//cin.ignore('\n');
		getline(cin,data);
	}
	int count=0;
	cout<<"KEyword is "<<keyword<<endl;
	for(int i=0;i<keyword.size();i++)
	{
		 if(s.find(keyword[i]) == s.end())
		 {
		 	s.insert(keyword[i]);
		 	count++;
		 }		
	}
	cout<<"COUNT IS"<<count<<endl;
	return 0;
}