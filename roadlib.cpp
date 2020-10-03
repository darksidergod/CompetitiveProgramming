#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define F first
#define S second
#define vi vector<int>
#define SIZE 200000
bool vis[SIZE];
vi adj[SIZE];

int dfs(int root)
{
	int nodes=1LL;
	stack<int> s;
	s.push(root);
	vis[root]=true;
	while(!s.empty())
	{
		int u=s.top();
		s.pop();
		flp(i, 0, adj[u].size())
		{
			int v=adj[u][i];
			if(!vis[v])
			 s.push(v); 	
		}
		if(!vis[u]){
		 nodes++;
		 vis[u]=true; 
		// cout<<"visited "<<u<<"\n";
			}
	}
	//cout<<nodes<<"\n";
	return nodes;
}
int32_t main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, m, r, l, ans=0;
		cin>>n>>m>>l>>r;
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<n; i++)
			adj[i].clear();

		for(int i=0; i<m; i++)
		{
			int u, v;
			cin>>u>>v;
			u--; v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		for(int i=0; i<n; i++)
		{
			if(!vis[i])
			{
				int visited=dfs(i);
				if(r<l)
				 ans+=(visited-1)*r+l;
				else
				 ans+=visited*l;
			}
		}

		

		cout<<ans<<"\n";
	}
	return 0;
}