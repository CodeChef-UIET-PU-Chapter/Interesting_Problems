#include<bits/stdc++.h>
#define int long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define limit 10000
#define mod 1000000009

template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

int N,M;
    
class QItem { 
public: 
    int row; 
    int col; 
    int dist; 
    QItem(int x, int y, int w) 
        : row(x), col(y), dist(w) 
    { 
    } 
}; 
  
int minDistance(vector<vector<char>> grid) 
{ 
    QItem source(0, 0, 0); 
   
    bool visited[N][M]; 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < M; j++) 
        { 
            if (grid[i][j] == '0') 
                visited[i][j] = true; 
            else
                visited[i][j] = false; 
  
            if (grid[i][j] == 's') 
            { 
               source.row = i; 
               source.col = j; 
            } 
        } 
    } 
  
    queue<QItem> q; 
    q.push(source); 
    visited[source.row][source.col] = true; 
    while (!q.empty()) { 
        QItem p = q.front(); 
        q.pop(); 
   
        if (grid[p.row][p.col] == 'd') 
            return p.dist; 
   
        if (p.row - 1 >= 0 && 
            visited[p.row - 1][p.col] == false) { 
            q.push(QItem(p.row - 1, p.col, p.dist + 1)); 
            visited[p.row - 1][p.col] = true; 
        } 
   
        if (p.row + 1 < N && 
            visited[p.row + 1][p.col] == false) { 
            q.push(QItem(p.row + 1, p.col, p.dist + 1)); 
            visited[p.row + 1][p.col] = true; 
        } 
  
        if (p.col - 1 >= 0 && 
            visited[p.row][p.col - 1] == false) { 
            q.push(QItem(p.row, p.col - 1, p.dist + 1)); 
            visited[p.row][p.col - 1] = true; 
        } 

        if (p.col + 1 < M && 
            visited[p.row][p.col + 1] == false) { 
            q.push(QItem(p.row, p.col + 1, p.dist + 1)); 
            visited[p.row][p.col + 1] = true; 
        } 
    } 
    return -1; 
} 

signed main()
{
    io;
    int test_case;
	//cin>>test_case;
    test_case=1;
	while(test_case--)
	{
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<char>> mat(n);
        char s;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>s;
                if(s=='#')
                mat[i].push_back('0');
                else
                mat[i].push_back('*');

                if(s=='S')
                mat[i][j]='s';
                else if(s=='E')
                mat[i][j]='d';

            }
        }
        int x,y,d;
        for(int i=0;i<k;i++)
        {
            cin>>x>>y>>d;
            x--;
            y--;
            mat[x][y]='0';
            int p=max(x-d,0LL);
            int tempx=x;
            while(tempx!=p-1)
            {
                mat[tempx][y]='0';
                tempx--;
            }
            p=min(x+d,n);
            tempx=x;
            while(tempx!=p+1)
            {
                mat[tempx][y]='0';
                tempx++;
            }
            p=max(y-d,0LL);
            tempx=y;
            while(tempx!=p-1)
            {
                mat[x][tempx]='0';
                tempx--;
            }
            p=min(y+d,m);
            tempx=y;
            while(tempx!=p+1)
            {
                mat[x][tempx]='0';
                tempx++;
            }
        }

        N=n;
        M=m;
        int dist = minDistance(mat);
 
        if (dist != -1)
            print(dist);
        else
            cout << "IMPOSSIBLE\n";
    }         
}

