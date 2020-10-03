#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>

vi adj[100001];
bool visited[100001];

void initialise()
{
	for(ll i=0; i<100001; i++)
		adj[i].clear();

}

ll dfs(ll r, ll* array)
{
	ll ans=0;
	stack<ll> s;
	s.push(r);
	ans+=array[r];
	visited[r]=true;
	while(!s.empty())
	{
		ll v = s.top();
		if(!visited[v])
			ans+=array[v];
		s.pop();
		for(ll j=0; j<(ll)adj[v].size(); j++)
		{
			if(!visited[adj[v][j]])
				s.push(adj[v][j]);
		}
		if(!visited[v])
			{
				visited[v]=true;
			}
	}
	return ans;
}

int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		initialise();
		memset(visited, 0, sizeof(visited));
		ll n, m, x, y, score=0;
		cin>>n>>m;
		ll a[n];

		for(ll i=0; i<m; i++)
			{
				cin>>x>>y;
				adj[x-1].push_back(y-1);
				adj[y-1].push_back(x-1);
			}

		for(ll i=0; i<n; i++)
			cin>>a[i];

		for(ll i=0; i<n; i++)
		{
			if(!visited[i])
			{
				ll temp;
				temp=dfs(i, a);
				if(temp>score)
					score=temp;
			}
		}

		cout<<score<<"\n";
	}
	return 0;
}
