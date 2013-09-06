#include<iostream>
#include<stdlib.h>
#include <time.h>       /* time */
using namespace std;
bool solveMaze(char maze[8][8],int x,int y,bool mazeVisited[8][8]);
bool isMazeSolvable(char maze[8][8]);
int main(int argc, char const *argv[])
{
	char maze[8][8];
	srand (time(NULL));
	
	//Maze Generation Code;
	int start_x = rand() % 8;
	int start_y = rand() % 8;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(rand()%2)
			maze[i][j] = '*';
			else
			maze[i][j] = ' ';
			
		}
		/* code */
	}
	int end_x = rand() % 8;
	int end_y = rand() % 8;
	while(start_x == end_x && start_y == end_y)
	{
		end_x = rand() % 8;
		end_y = rand() % 8;	
	}
	maze[start_x][start_y] = 's';
	maze[end_x][end_y] = 'e';

	cout<<"Generated Maze"<<endl;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cout<<maze[i][j]<<" ";
			
		}
		cout<<endl;
		/* code */
	}
	if(isMazeSolvable(maze))
	cout<<"Yes!!!"<<endl;
	else
	cout<<"No!!!"<<endl;

	return 0;
}
bool isMazeSolvable(char maze[8][8])
{
	int start_x = -1,start_y = -1;
	bool mazeVisited[8][8];
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(maze[i][j] == 's')
			{
				start_x = i;
				start_y = j;
			}
		}
		/* code */
	}

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			mazeVisited[i][j] = false;
		}
		/* code */
	}
	if(start_x == -1)
		return false;
	if(solveMaze(maze,start_x,start_y,mazeVisited))
		return true;
}
bool solveMaze(char maze[8][8],int x,int y,bool mazeVisited[8][8])
{
	if(y>7 || y <0 || x <0 || x>7)
		return false;
	if(maze[x][y] == '*')
		return false;
	if(maze[x][y] == 'e')
		return true;
	if(mazeVisited[x][y] == false)
		{
			mazeVisited[x][y] = true;
			if(solveMaze(maze,x,y-1,mazeVisited))
			return true	;	
			if(solveMaze(maze,x,y+1,mazeVisited))
				return true;
			if(solveMaze(maze,x+1,y,mazeVisited))
				return true;
			if(solveMaze(maze,x-1,y,mazeVisited))
				return true;
		}
	return false;	

}

