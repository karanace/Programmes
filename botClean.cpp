#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
/* Head ends here */
void next_move(int posr, int posc, vector <string> board) 
{
    //add logic here
    int myi=posr,myj=posc,pi=-1,pj=-1;

    vector< pair<int,int> > dirty;
    
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(board[i][j] == 'd')
            {
                   dirty.push_back(make_pair(i,j));
            }
            
        }
    }
    
 
    while(!dirty.empty())
    {
            int sum =100000;
            int gotoi = -1;
            int x;
        for(int i=0;i<dirty.size();i++)
        {
            x = fabs(myi -dirty[i].first) + fabs(myj-dirty[i].second);
            if( x < sum)
            {
                gotoi = i;
                sum = x;
            }
        }
    pi = dirty[gotoi].first;    
    pj = dirty[gotoi].second;
    dirty.erase(dirty.begin() + gotoi);
    
    if(pi>myi &&pj>myj)
    {
        while(pi>myi)
        {
            myi++;
            cout<<"DOWN"<<endl;
        }
        while(pj>myj)
        {
            myj++;
            cout<<"RIGHT"<<endl;
        }
       
    }
    else if(pi>myi &&pj<myj)//RIGHT
    {
        while(pi>myi)
        {
            myi++;
            cout<<"DOWN"<<endl;
        }
        while(pj<myj)
        {
            myj--;
            cout<<"LEFT"<<endl;
        }
    }
    else if(pi<myi &&pj>myj) //RIGHT
    {
        while(pi<myi)
        {
            myi--;
            cout<<"UP"<<endl;
        }
        while(pj>myj)
        {
            myj++;
            cout<<"RIGHT"<<endl;
        }
    }
    else if(pi<myi && pj <myj)
    {
        while(pi<myi)
        {
            myi--;
            cout<<"UP"<<endl;
        }
        while(pj<myj)
        {
            myj--;
            cout<<"LEFT"<<endl;
        }
    }
    if(pi==myi && pj ==myj)
    {
        cout<<"CLEAN"<<endl;
    }
    }
    
    

}
/* Tail starts here */
int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}