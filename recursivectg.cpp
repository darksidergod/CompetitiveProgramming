#include <bits/stdc++.h>
#define ll long long int
#define ii pair<int, int> 
#define pb push_back
#define f first
#define s second

using namespace std;

#define SIZE 1000001

vector<int> adj[SIZE];
bool vis[SIZE];
ll col[SIZE];
ll sz;
ll colRed;

void dfs(ll r, ll color)
{
	if(vis[r])
		return;

	vis[r]=1;
	colRed+=color;
	col[r]=color;
	sz++;
	for(ll i:adj[r])
		dfs(i, (1+color)%2);
	
}

int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n, m, ans=0;
		bool valid=true;
		cin>>n>>m;
		vector< pair<ll, ll> > edges;
		for(int i=1; i<=n; i++)
			adj[i].clear();

		memset(vis, 0, sizeof(vis));
		memset(col, -1, sizeof(col));

		for(int i=0; i<m; i++)
		{
			ll u, v;
			cin>>u>>v;
			edges.push_back({u,v});
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		for(int i=1; i<=n; i++)
		{
			if(!vis[i])
			{
				sz=0;
				colRed=0;
				dfs(i, 0);
				ans+=max(sz-colRed, colRed);
			}
		}

		for(int i=0; i<m; i++)
		{
			pair<ll, ll> p;
			p=edges[i];
			if(col[p.f]==col[p.s])
				valid=false;
		}

		if(!valid)
			cout<<"NO\n";
		
		else
			cout<<ans<<"\n";
	}

	return 0;
}