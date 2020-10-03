#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
#define SIZE 20000

ll power(ll a, ll b) {
ll x = 1, y = a;
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

vector<int> adj[SIZE];
bool visited[SIZE];

void dfs(int r)
{
    stack<int> s;
    visited[r]=true;
    for(int i=0; i<adj[r].size(); i++)
    {
        if(!visited[adj[r][i]])
            s.push(adj[r][i]);
    }

    while(!s.empty())
    {
        int v = s.top();
        s.pop();
        for(int j=0; j<adj[v].size(); j++)
        {
            if(!visited[adj[v][j]])
                s.push(adj[v][j]);
        }
        visited[v]=true;
    }
}

int main(void)
{
    int n, cc=0;
    cin>>n;
    int v[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>v[i];
        adj[i].pb(v[i]);
        adj[v[i]].pb(i);
    }

    for(int i = 1;i <= n;++i) 
    {
     if(visited[i] == false)     
      {
         dfs(i);
         cc++;
      }
    }

    cout<<cc<<"\n";
    return 0;

}