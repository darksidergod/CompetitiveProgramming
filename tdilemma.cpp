#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long int
#define SIZE 1000000
ll mod = 1000000007;
ll root[SIZE], size[SIZE];
map<ll, ll> mp;
ll n;

ll getroot(ll u)
{
	while(root[u]!=u)
	{	
		root[u]=root[root[u]];
		u = root[u];
	}

	return u;

}

void unionNodes(ll u, ll v)
{
	ll r_u=getroot(u);
	ll r_v=getroot(v);
	if(size[r_u]>size[r_v])
	{
		root[r_v]=root[r_u];
		size[r_u]+=size[r_v];
		size[r_v]=0;
	}

	else
	{
		root[r_u]=root[r_v];
		size[r_v]+=size[r_u];
		size[r_u]=0;
	}
    
}

int main(void)
{
	ll m;
	cin>>n>>m;
	
	for(ll i=0; i<n; i++)
	{
		root[i]=i;
		size[i]=1;
	}

	for(ll i=0; i<m; i++)
	{
		ll x, y;
		cin>>x>>y;
		unionNodes(x-1, y-1);
	}	

	for(ll i=0; i<n; i++)
		mp[getroot(i)]++;

	ll ans=1;
	for(auto i:mp)
		ans=(ans*i.second)%mod;

	//cout<<"\n";
	cout<<ans<<"\n";


	return 0;
}