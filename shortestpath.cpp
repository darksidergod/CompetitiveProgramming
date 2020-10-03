//Dijkstra's using min_prioriy_queue
//O(V+ElogV)

#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long int
#define SIZE 1000000 

using namespace std;

vector < pair < ll,ll> > v[SIZE];  
bool vis[SIZE];
ll dist[SIZE];

void djk()
{
	memset(vis, false, sizeof(vis));
	dist[1]=0;
	multiset < pair <ll,ll> > s;
	s.insert({0,1});
	while(!s.empty())
	{
		pair< ll, ll> p = *(s.begin());
		s.erase(s.begin());

		ll u = p.second;
		if(vis[u])continue;
		 vis[u]=true;
		
		for(ll i=0; i<(ll)v[u].size(); i++)
		{
			ll e = v[u][i].first;
			ll w = v[u][i].second;
			if( dist[e]>(dist[u]+w) )
			{
				dist[e]=(dist[u]+w);
				s.insert({dist[e], e});
			}
		}
	}
}


int main(void)
{
	ll n, m;
	ll x, y, w;
	cin>>n>>m;
	
	for(ll i=0; i<m; i++)
	{
		cin>>x>>y>>w;
		pair<ll, ll> p;
		p = {y, w};
		v[x].push_back(p);
	}

	for(ll j=2; j<=n; j++)
		dist[j]=INT_MAX;

	djk();

	//for(ll i=2;i<=n; i++)
		cout<<dist[n];
	
	cout<<"\n";

	return 0;


}