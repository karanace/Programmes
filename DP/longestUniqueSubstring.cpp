#include <iostream>
using namespace std;
int longestUniqueSubstring(string s);
int main(int argc, char const *argv[])
{
	/* code */
	string s = "GEEKSFORGEEKS";
	cout<<"Length of longest Unique Substring is\t"<<longestUniqueSubstring(s)<<endl;
	return 0;
}
int longestUniqueSubstring(string s)
{
	int visited[256];
	int cur_len =1;
	int max_len = 1;
	int prev_index;
	for (int i = 0; i < 256; ++i)
	{
		visited[i] = -1;
	}
	visited[s[0]] = 0;	//Marking with its index
	for (int i = 1; i < s.size(); ++i)
	{
		prev_index = visited[s[i]];
		if(prev_index == -1 || i - cur_len > prev_index)
		cur_len++;
		else 
			{	
				if(cur_len > max_len)
					max_len = cur_len;
				cur_len = i - prev_index;
			}
		visited[s[i]] = i;
	}
	if(cur_len >max_len)
		max_len = cur_len;

	return max_len;
}
