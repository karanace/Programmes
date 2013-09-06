#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
class ZigZag
{
	
	public :
		int longestZigZag(vector<int> sequence)
		{
			int size = sequence.size();
			int sign[size];
			int len[size];
			for (int i = 0; i < size; ++i)
				{
					len[i] = 1;
					sign[i]= 0;
				}
			
			for (int i = 0; i < size -1; ++i)
			{
				for (int j = i+1; j <size; ++j)
				{
					/* code */
					if(sign[i]>0)
					{
						if(sequence[j] < sequence[i])
						{
							if(len[j] < len[i] +1)
							{
								len[j] = len[i] +1;
								sign[j] = -1;	
							}
						}	
					}
					else 
					{	
						if(sign[i] == 0)
						{
							if(sequence[j] < sequence[i])
							{
								if(len[j] < len[i] +1)
								{
									len[j] = len[i] +1;
									sign[j] = -1;	
								}
							}
							if(sequence[j] > sequence[i])
							{
								if(len[j] < len[i] +1)
								{
									len[j] = len[i] +1;
									sign[j] = +1;	
								}
							}			
						}
						else
						{
							if(sequence[j] > sequence[i])
						{
							if(len[j] < len[i] +1)
							{
								len[j] = len[i] +1;
								sign[j] = +1;	
							}
						}
						}
					}
					}
					

				}
				for (int i = 0; i < size; ++i)
		{
			cout<<"Len "<<i<<" "<<len[i]<<endl;
		}
		return *max_element(len,len + size);
			}
		
	
	
	
};
int main()
{
	vector<int> v ;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	/*v.push_back(7);
	v.push_back(8);
	v.push_back(9);*/
	
	ZigZag z;

	cout<<"z.longestZigZag(v) "<<z.longestZigZag(v)<<endl;

}