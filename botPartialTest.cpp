#include<iostream>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
/* Head ends here */
bool checkDirty(int i,int j,const vector<string> &board)
{
    if(i<0 || i>4 || j<0 || j>4 )
    return false;
    if(board[i][j] == 'd')
    return true;    
}
bool check(int i,int j)
{
    if(i<0 || i>4 || j<0 || j>4 )
    return false;
    return true;    
}
void next_move(int posx, int posy, vector <string> board) {
    //add logic here
    int myi=posx,myj=posy,pi,pj;
    vector< pair<int,int> > dirty;

      for(int i=-1;i<2;i++)
    {
        for(int j=-1;j<2;j++)
        {
            
            if(checkDirty(myi+i,myj+j,board))
            {
                dirty.push_back(make_pair(myi+i,myj+j));
            }
        }
    }

    int sum =100000;
    int gotoi = -1;
    int x;
    if(!dirty.empty())
    {
        for(int i=0;i<dirty.size();i++)
            {
                x = fabs(myi -dirty[i].first) + fabs(myj-dirty[i].second);
                cout<<"i and j "<<dirty[i].first<<" "<<dirty[i].second<<endl;
                if( x < sum)
                {
                    gotoi = i;
                    sum = x;
                }
            }
    
        pi = dirty[gotoi].first;    
        pj = dirty[gotoi].second;
        dirty.erase(dirty.begin() + gotoi);
        cout<<"my i "<<myi<<endl;
        cout<<"my j "<<myj<<endl;
        cout<<"p i "<<pi<<endl;
        cout<<"p j "<<pj<<endl;

        if(pi>myi)
        {
            cout<<"DOWN"<<endl;
        }
        else 
        {
            if(pi==myi)
            {
                if(pj>myj)
                cout<<"RIGHT"<<endl;
                else if(pj<myj)
                cout<<"LEFT"<<endl;
                else
                cout<<"CLEAN"<<endl;
            }
            else
            {
                cout<<"UP"<<endl;
            }
        }        
}    
else
{
    int c;
    bool atLeastOnce = true;
    srand(time(NULL));
    do 
    {
        c  = rand()%4;
        switch(c)
        {
            case 0:
                    if(check(myi,myj+1))
                    {
                        cout<<"RIGHT"<<endl;    
                        atLeastOnce = false;    
                    }
                    break;
            case 1: 
                    if(check(myi,myj-1))
                    {
                        cout<<"LEFT"<<endl;
                        atLeastOnce = false;
                    }
                    break;
            case 2:    
                    if(check(myi+1,myj))
                    {
                        cout<<"DOWN"<<endl;
                        atLeastOnce = false;
                    }
                    break;
            case 3:
                    if(check(myi-1,myj))
                    {
                        cout<<"UP"<<endl;
                        atLeastOnce = false;
                    }
                    break;
        
    }    
    }while(atLeastOnce);
}
}
/* Tail starts here */
int main(void) {
    int pos[2];
    vector <string> board,dirty;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    while(1)
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                dirty.push_back(make_pair(i,j));
            }
        }
        next_move(pos[0], pos[1], board);
    }
    
    return 0;
}