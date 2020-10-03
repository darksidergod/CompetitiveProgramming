#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back
#define SIZE 6001
vi adj[SIZE];

int cost[SIZE][SIZE];
int points[SIZE];
int science[SIZE];


void dfs(int v, int capacity, int res)
{
	//cout<<"capacity at "<<v<<" is "<<capacity<<"\n";
	if(capacity<0)
		return;
	points[v]=res;
	for(int i=0; i<(int)adj[v].size(); i++)
	{
		int to=adj[v][i];
		//if(points[to]==0 || res+science[to]>points[to])
			dfs(to, capacity-cost[v][to], res+science[to]);
	}
}

int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(cost, 0, sizeof(cost));
		memset(science, 0, sizeof(science));
		memset(points, 0, sizeof(points));
		int n, m, fuel;
		cin>>n>>m>>fuel;
		for(int i=0; i<n; i++)
			adj[i].clear();
		
		
		for(int i=0; i<n; i++)
			cin>>science[i];

		for(int i=0; i<m; i++)
		{
			int u, v, c;
			cin>>u>>v>>c;
			adj[u].pb(v);
			cost[u][v]=c;
		}

		dfs(0, fuel, science[0]);

		sort(points, points+n);
		cout<<points[n-1]<<"\n";a

	}
	return 0;
}