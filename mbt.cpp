// CODE ONLY WORKS IF THE GIVEN EDGES ARE NOT REPEATED
#include <bits/stdc++.h>
#define ll long long int 
#define vi vector<int>
#define ii pair<int, int>

using namespace std;

bool visited[1001];
vi adj[1001];

ll dfs(ll u)
{
	ll ans=0;
	stack<ll> s;
	s.push(u);
	visited[u]=true;
	while(!s.empty())
	{
		ll v = s.top();
		s.pop();
		for(ll j=0; j<(ll)adj[v].size(); j++)
		{
			if(!visited[adj[v][j]])
				s.push(adj[v][j]);
		}
		//cout<<"added for "<<v<<"\n";
		ans++;	
		visited[v]=true;
		
	}
	//cout<<"ans for this iteration is "<<ans<<"\n";
	return ans;
}	

int main(void){
	ll n, d, ans=INT_MAX, cur_count;
	cin>>n>>d;

	//memset(adj, 0, sizeof(adj));
	for(int k=0; k<d; k++)
	{
		ll u, v;
		cin>>u>>v;
		adj[u].push_back(v);
	}

	for(int node=1; node<=n; node++)
	{
		memset(visited, 0, sizeof(visited));
		cur_count=dfs(node);
		if(ans>cur_count)
			ans=cur_count;
	}

	cout<<ans<<"\n";
	return 0;

}