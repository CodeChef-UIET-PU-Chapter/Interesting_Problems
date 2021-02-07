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

vector<int> node[N+1];
bool vis[N+1];

int outdegree;

void dfs(int child)
{
    vis[child]=true;
    int p=node[child].size();
    if(p==0)
    p=1;
    outdegree=max(outdegree,p);
    for(auto x: node[child])
    if(!vis[x])
    dfs(x);
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
        map<pair<int,int>,int> store;
        int cnt=1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                store[{i+1,j+1}]=cnt;
                cnt++;
            }    
        }    

        
        int a,b,c,d;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>c>>d;
            node[store[{a,b}]].push_back(store[{c,d}]);
            node[store[{c,d}]].push_back(store[{a,b}]);
        }

        int ans=0;
        outdegree=0;
        for(int i=1;i<=n*n;i++)
        {
            if(!vis[i])
            dfs(i);
            ans+=outdegree;
            outdegree=0;
        }
        print(ans);
    }
}
