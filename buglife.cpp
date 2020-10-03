#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define F first
#define pb push_back
#define S second
#define SIZE 1000000

int power(int a, int b) {
int x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}


int color[SIZE];
vector<int> adj[SIZE];
bool vis[SIZE];


void bfs(int root)
{
    queue<int> q;
    q.push(root);
    vis[root]=true; color[root]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        flp(j, 0, adj[u].size())
        {
            int v=adj[u][j]; 
            if(!vis[v])
            {
                q.push(v);
                vis[v]=true;
                color[v]=(1+color[u])%2;
            }
        }
    }
}


int32_t main(void)
{
    int t;
    cin>>t;
    flp(x, 0, t)
    {
        memset(color, -1, sizeof(color));
        int n, m;
        cin>>n>>m;
        flp(i, 0, n)
        adj[i].clear();
        memset(vis, 0, sizeof(vis));
        vector<pair<int, int>> edges;
        bool flag=true;
        flp(i, 0, m)
        {
            int u, v;
            cin>>u>>v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
            edges.push_back({u, v});
        }
        
        flp(i, 0, n)
        {
            if(!vis[i])
                bfs(i);
        }

       /* flp(i, 0, n)
         cout<<color[i]<<" ";
        cout<<"\n";*/
        for(auto i:edges)
        {
            if(color[i.F]==color[i.S] && i.F!=i.S)
                {
                    flag=false;
                  //  cout<<i.F<<" "<<i.S<<"\n";
                }
        }

        cout<<"Scenario #"<<x+1<<":\n";
        if(flag)
        {
            cout<<"No suspicious bugs found!"<<"\n";
        }

        else
        {
            cout<<"Suspicious bugs found!"<<"\n";
        }
    }
}