#include <bits/stdc++.h>
 
using namespace std;
#define ll unsigned long long int
#define SIZE 2000000
#define ft first
#define sd second
#define pb push_back
 
ll mod = 1000000007;
ll root[SIZE], size[SIZE];
 
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

	return;
    
}
 
int main(void)
{
	ll n, ans=0, u, v, q2, q1;
	cin>>n;
	map<int,int> mp;

	for(int i=0; i<n; i++){ root[i]=i; size[i]=1; }
	cin>>q1;
	
	for(ll i=0; i<q1; i++){ cin>>u>>v; unionNodes(u-1, v-1); }
 	
 	for(ll i=0; i<n; i++) mp[getroot(i)]++;
	
	cin>>q2;

	for(ll j=0; j<q2; j++){
		cin>>u>>v;
		u-=1; v-=1;
		if(getroot(u)==getroot(v)) size[getroot(u)]=0;	
	}

	for(int i=0; i<n; i++) ans=max(ans, size[i]);
	cout<<ans<<"\n";
 
  
	return 0;
	
 
	
}