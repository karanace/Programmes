#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
/* Head ends here */
void next_move(int posr, int posc,int dimx, int dimy, vector <string> board) 
{
    //add logic here
    int myi=posr,myj=posc,pi=-1,pj=-1;

    
    vector< int > newDirty;
    
    for(int i=0;i<dimx;i++)
    {
        for(int j=0;j<dimy;j++)
        {
            if(board[i][j] == 'd')
            {
                   newDirty.push_back(i*dimy+j);
            }
            
        }
    }
    
 
            int sum =100000;
            int gotoi = -1;
            int x;
                   sort(newDirty.begin(),newDirty.end());
        int xy =newDirty[newDirty.size()/2];



    pi = xy/dimy;    
    pj = xy%dimy;
    
    
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


/* Tail starts here */
int main(void) {
    int pos[2];
    int dim[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    cin>>dim[0]>>dim[1];
    for(int i=0;i<dim[0];i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], dim[0], dim[1], board);
    return 0;
}