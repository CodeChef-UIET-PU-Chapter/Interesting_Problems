#include<bits/stdc++.h>
#define int long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 10000000
#define limit 10000

template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

vector<int> v[N+1];
bool vis[N+1];
int friends[N+1];
map<pair<int,int>,int> tol;

void printPath(vector<int> stack)
{
    int rupees=0,ans=0;
    for(int i=0;i<stack.size()-1;i++)
    {
        rupees+=friends[stack[i]];
        if(rupees<tol[{stack[i+1],stack[i]}])
        ans+=tol[{stack[i+1],stack[i]}]-rupees;

        rupees-=tol[{stack[i+1],stack[i]}];
        if(rupees<0)
        rupees=0;
    }
    print(ans);
}
 
void DFS(int x,int y,vector<int> stack)
{
    stack.push_back(x);
    if (x == y) {
        printPath(stack);
        return;
    }
    vis[x] = true;
 
    if (!v[x].empty()) {
        for (int j = 0; j < v[x].size(); j++) {
            if (vis[v[x][j]] == false)
                DFS(v[x][j], y, stack);
        }
    }
 
    stack.pop_back();
}
 
void DFSCall(int x,int y,int n,vector<int> stack)
{
    memset(vis, false, sizeof(vis));
    DFS(x, y, stack);
}
signed main()
{
    io;
    int test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> stack;
        for(int i=1;i<=n;i++) cin>>friends[i];    

        
        int a,b,c;
        for(int i=0;i<n-1;i++)
        {
            cin>>a>>b>>c;
            tol[{a,b}]=c;
            tol[{b,a}]=c;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        int source,des;
        for(int i=0;i<m;i++)
        {
            cin>>source>>des;
            DFSCall(source,des, n, stack);
        }
    }
}
