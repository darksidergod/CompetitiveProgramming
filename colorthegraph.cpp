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
ll color[SIZE];

ll dfs(ll r)
{
	ll ans=0, sz=0;
	stack<ll>s;
	s.push(r);
	vis[r]=true;
	color[r]=0;
	ans++; sz++;
	while(!s.empty())
	{
		ll v=s.top();
		s.pop();
		for(ll i=0; i<(ll)adj[v].size(); i++)
		{
			if(!vis[adj[v][i]])
			{
				s.push(adj[v][i]);
				color[adj[v][i]]=(1+color[v])%2;
				sz++;
				if(color[adj[v][i]]==0)
					ans++;
			}
		}
		vis[v]=true;
	}

	return max(sz-ans, ans);
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
		memset(color, -1, sizeof(color));

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
				ans+=dfs(i);
		}

		for(int i=0; i<m; i++)
		{
			pair<ll, ll> p;
			p=edges[i];
			if(color[p.f]==color[p.s])
				valid=false;
		}

		if(!valid)
			cout<<"NO\n";
		
		else
			cout<<ans<<"\n";
	}

	return 0;
}