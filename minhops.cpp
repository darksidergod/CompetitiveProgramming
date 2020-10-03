//Dijkstra's using min_prioriy_queue
//O(V+ElogV)

#include <bits/stdc++.h>
#define f first
#define s second
#define ll unisgned long long int
#define SIZE 1000000 

using namespace std;

vector < pair < ll,ll> > v[SIZE];
vector<pair <ll, ll> > lastedge;  
bool vis[SIZE];
bool bothtypes[SIZE];
ll dist[SIZE];
ll edge[SIZE];
ll hopcount[SIZE];

void djk()
{
	memset(vis, false, sizeof(vis));
	memset(bothtypes, false, sizeof(bothtypes));
	dist[1]=0;
	edge[1]=0;
	hopcount[1]=0;
	multiset < pair <ll,ll> > s;
	s.insert({0,1});
	while(!s.empty())
	{
		pair< ll, ll> p = *(s.begin());
		s.erase(s.begin());
		ll fromNode = p.second;
		if(vis[fromNode])continue;
		 vis[fromNode]=true;
		
		for(ll i=0; i<(ll)v[fromNode].size(); i++)
		{
			ll toNode = v[fromNode][i].first;
			ll w = v[fromNode][i].second;
			if( dist[toNode]>(dist[fromNode]+w) )
			{		
				dist[toNode]=(dist[fromNode]+w);
				edge[toNode]=w;
				//cout<<edge[toNode]<<" "<<dist[toNode]<<" for node "<<toNode<<"\n";
				s.insert({dist[toNode], toNode});
				if( ((w+edge[fromNode])%2==0) || bothtypes[fromNode] || fromNode==1)
					hopcount[toNode]=hopcount[fromNode];

				else
					hopcount[toNode]=(1+hopcount[fromNode]);
			}

			else if(dist[toNode]==(dist[fromNode]+w))
			{
				if( (edge[toNode]%2==0 && w%2!=0) || (edge[toNode]%2!=0 && w%2==0) )
					bothtypes[toNode]=1;

				else if(((w+edge[fromNode])%2==0))
				{
					//cout<<"equal dist condition with same edge\n";
					s.insert({dist[toNode], toNode});
					edge[toNode]=w;
					hopcount[toNode]=hopcount[fromNode];
				}
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
		p={x, w};
		v[y].push_back(p);
	}

	for(ll j=0; j<=n; j++)
		dist[j]=ULONG_MAX;
	djk();
	cout<<dist[n]<<" "<<hopcount[n]<<"\n";
	return 0;
}