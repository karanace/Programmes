#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Boxing
{
int indexJudge[5],score[5],exhausted[5],currentScore,intervals;
public :

Boxing()
{	
	currentScore=0;
	intervals =0;
	for(int i=0;i<5;++i)
		{
			indexJudge[i] = score[i] = exhausted[i] = 0;
		}
}
void minIndices(vector<int> a,vector<int> &v)
{
	int min=999998;

	for(int i=0;i<a.size();i++)
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
	
}
int judgeExhausted()
{
	return exhausted[0] + exhausted[1] + exhausted[2] + exhausted[3] + exhausted[4];
}
int calScore()
{
	return score[0] + score[1] + score[2] + score[3] + score[4];	
}
int maxCredit(vector<int> judge1,vector<int> judge2,vector<int> judge3,vector<int> judge4,vector<int> judge5)
	{		
		while(judgeExhausted() <3)
		{
			vector<int> a,v;
			
				if(indexJudge[0] < judge1.size())
				a.push_back(judge1.at(indexJudge[0]));
				else
				{
					a.push_back(999999);
					exhausted[0] = 1;	
					
				}
				
				if(indexJudge[1] < judge2.size())
				a.push_back(judge2.at(indexJudge[1]));
				else
				{
					a.push_back(999999);
					exhausted[1] = 1;	
					
				}
				if(indexJudge[2] < judge3.size())
				a.push_back(judge3.at(indexJudge[2]));
				else
				{
					a.push_back(999999);
					exhausted[2] = 1;	
					
				}
				if(indexJudge[3] < judge4.size())
				a.push_back(judge4.at(indexJudge[3]));
				else
				{
					a.push_back(999999);
					exhausted[3] = 1;	
					
				}
				if(indexJudge[4] < judge5.size())
				a.push_back(judge5.at(indexJudge[4]));
				else
				{
					a.push_back(999999);
					exhausted[4] = 1;	
					
				}
				minIndices(a,v);
				
				for(int j=0;j<v.size();j++)
				{
					switch(v.at(j))
					{
						case 0: score[0] = 1;
								indexJudge[0]++;
								break;
						case 1: score[1] = 1;
								indexJudge[1]++;
								break;
						case 2: score[2] = 1;
								indexJudge[2]++;
								break;
						case 3: score[3] = 1;
								indexJudge[3]++;
								break;
						case 4: score[4] = 1;
								indexJudge[4]++;
					}
				}
				currentScore = calScore();
				
				if(currentScore >=3)
				{
					for (int i = 0; i < 5; ++i)
					{
						score[i] =0;
					}
					currentScore = 0;
					intervals++;	
					
				}
		
		}
		return intervals;
	} 
	
};




