#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define rev(i, k) for(int i=k; i>=0; i--)
#define F first
#define S second
#define SIZE (int)(3e5)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool tourist[SIZE];
bool vis[SIZE];
int sbt[SIZE];
int lv[SIZE];
vector<int> adj[SIZE];
void bfs(int root, int par)
{
    if(par==-1)
     lv[root]=0;

    flp(i, 0, adj[root].size())
    {
        int v=adj[root][i];
        if(v==par) continue;

        lv[v]=1+lv[root];
        bfs(v, root);
    }
     
}
void dfs(int root, int par)
{
    if(!tourist[root]) sbt[root]=1;
    else sbt[root]=0;
    
    
    flp(i, 0, adj[root].size())
    {
        int v=adj[root][i];
        if(v==par) continue;
        dfs(v, root);
        sbt[root]+=sbt[v];
    }
}
int32_t main(void)
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k; k=n-k;
        vector<pair<int, int>> v1, v2;
        int u, v, ct=0;
        flp(i, 0, n-1)
        {
            cin>>u>>v;
            u--; v--;
            adj[u].pb(v); adj[v].pb(u);     
        }
        flp(i, 1, n)
            v1.pb({adj[i].size(), i});
        
        tourist[0]=true;
        sort(v1.begin(), v1.end());
        rev(i, v1.size()-1)
        {
            if(ct==(k-1)) break;

            if(v1[i].F>1)
            {
                ct++;
                tourist[v1[i].S]=true;
            }
        }
        bfs(0, -1);
        flp(i, 0, n)
        {
            if(v1[i].F==1 && v1[i].S!=0)
                v2.pb({lv[v1[i].S], v1[i].S});
            
        }
        sort(v2.begin(), v2.end());
        if( ct!=(k-1) )
        {
            while(ct!=(k-1))
            {
                flp(i, 0, v2.size())
                {
                    tourist[v2[i].S]=true;
                    ct++;

                    if(ct==k-1)
                     break;
                }
            }
        }

        dfs(0, -1); int ans=0;       
        flp(i, 0, n)
        {
            if(tourist[i])
             ans+=sbt[i];
        }
        cout<<ans<<"\n";
        /*
        flp(i, 0, n)
         cout<<lv[i]<<" ";
        cout<<"\n";
        cout<<ans<<"\n";
        */
        
    }
    return 0;
}