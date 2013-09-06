#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
/* Head ends here */

bool push(int r1,int c1,int r,int c)
{
    if( r1 < 0 || r1 >=r  || c1 < 0 || c1 >= c)
        return false;
        return true;    
}
void dfs( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid)
{
    stack< pii > path;
    queue< pii > store;
    queue< pii > store1;
    bool visited[r][c] ;
    pii parent[r][c];
    for (int i = 0; i < r; ++i)
        {
            for(int j=0;j<c;j++)
                visited[i][j] = false;
        }    
    if(grid[pacman_r][pacman_c] !='.')
        visited[pacman_r][pacman_c] = true;
    path.push(make_pair(pacman_r,pacman_c));
    while(!path.empty())
    {
        pii state = path.top();
        
        //cout<<state.first<<" "<<state.second<<endl;
        path.pop();

        if( grid[state.first][state.second] == '.' )
        {
            store.push(state);
            break;
        }   
        else if(grid[state.first][state.second] == '-' || grid[state.first][state.second] == 'P')
        {
            
            if(visited[state.first -1][state.second] == false)
                if(push(state.first -1,state.second,r,c))
                {
                    path.push(make_pair(state.first -1,state.second));
                    parent[state.first-1][state.second] = state;
                    visited[state.first -1][state.second] = true;

                }
            if(visited[state.first ][state.second -1] == false)
                if(push(state.first,state.second-1,r,c))
                {
                    path.push(make_pair(state.first,state.second-1));
                    parent[state.first][state.second-1] = state;
                    visited[state.first][state.second-1] = true;
                }
            if(visited[state.first ][state.second+1] == false)
                if(push(state.first,state.second+1,r,c))
                {
                    path.push(make_pair(state.first,state.second+1));
                    parent[state.first][state.second+1] = state;
                    visited[state.first][state.second+1] = true;
                }
            if(visited[state.first +1][state.second] == false)
                if(push(state.first+1,state.second,r,c))
                {
                    path.push(make_pair(state.first+1,state.second));
                    parent[state.first+1][state.second] = state;
                    visited[state.first+1][state.second] = true;
                }
        }
        if( grid[state.first][state.second] != '%' )
        store.push(state);
        
    }
    cout<<store.size()<<endl;
    while(!store.empty())
    {
        pii f = store.front();
        store.pop();
        cout<<f.first<<" "<<f.second<<endl;
    }
  cout<<store1.size()-1<<endl;
    while(!store1.empty())
    {
        pii f = store1.front();
        store1.pop();
        cout<<f.first<<" "<<f.second<<endl;
    }
    
}

/* Tail starts here */
int main(void) {

    int r,c, pacman_r, pacman_c, food_r, food_c;
    
    cin >> pacman_r >> pacman_c;
    cin >> food_r >> food_c;
    cin >> r >> c;
    
    vector <string> grid;

    for(int i=0; i<r; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    dfs( r, c, pacman_r, pacman_c, food_r, food_c, grid);

    return 0;
}