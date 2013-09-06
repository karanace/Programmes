#include <vector>
#include <iostream>
using namespace std;

class ChessMetric{

public:
	long long howMany(int size,vector<int> start,vector<int> end,int numMoves)
	{
		unsigned long long data[100][100][60];
		int sx = start[0],sy = start[1];
		int ex = end[0],ey = end[1];
		data[sx][sy][0] = 1;
		for (int i = 1; i <= numMoves; ++i)
		{
			for (int r = 0; r < size; ++r)
			{
				for (int c = 0; c < size; ++c)
				{
					/* code */
					for (int j = -1; j < 2; ++j)
					{
						for (int k = -1; k < 2; ++k)
						{
							if(r+j>=0 && r+j<size && c+k>=0 && c+k<size)
							data[r+j][c+k][i] += data[r][c][i-1] ;
						}
					}
					for (int j = -2; j < 3; j += 4)
					{
						for (int k = -1; k < 2; k+=2)
						{
							if(r+j>=0 && r+j<size && c+k>=0 && c+k<size)
							data[r+j][c+k][i] += data[r][c][i-1] ;
						}
					}	

					for (int j = -1; j < 2; j += 2)
					{
						for (int k = -2; k < 3; k += 4)
						{
							if(r+j>=0 && r+j<size && c+k>=0 && c+k<size)
							data[r+j][c+k][i] += data[r][c][i-1]  ;
						}
					}	
				}
			}
			
		}
		cout << data[ex][ey][numMoves] << endl;
        return data[ex][ey][numMoves];

	}

	};
	int main(int argc, char const *argv[])
	{
		/* code */
		ChessMetric c;
		vector<int> v1,v2;
		v1.push_back(0);
		v1.push_back(0);
		v2.push_back(1);
		v2.push_back(0);
		c.howMany(3,v1,v2,1);
		return 0;
	}
