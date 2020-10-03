#include <bits/stdc++.h>

using namespace std;

#define ll long long int
bool vis[10001];

ll solve(ll u, ll v)
{
	if(u==v) return 0;
	if(vis[u])
		return INT_MAX;

	vis[u]=true;
	
	if(u<v)
		return v-u;

	if(u%2==0)
		return 1+solve(u/2, v);

	else
		return 1+solve(u+1, v);
		
}

int main(void)
{
	memset(vis, 0, sizeof(vis));
	ll ans=0, n, m;
	cin>>n>>m;
	//start=m;
	if(n>=m)
		ans=n-m;
	else
		ans=solve(m ,n);

	cout<<ans<<"\n";
	return 0;	
}