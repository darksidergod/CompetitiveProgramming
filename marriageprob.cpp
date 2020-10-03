#include <bits/stdc++.h>
 
using namespace std;
#define ll unsigned long long int
#define SIZE 2000000
#define ft first
#define sd second
#define pb push_back
 
ll mod = 1000000007;
ll root[SIZE], size[SIZE];

ll getroot(ll x)
{
	if(x != root[x]) {
		root[x] = getroot(root[x]);
	}
	return root[x];
}
 
void unionNodes(ll u, ll v)
{
	ll r_u=getroot(u);
	ll r_v=getroot(v);
	if(size[r_u]>size[r_v])
	{
		root[r_v]=root[r_u];
		size[r_u]+=size[r_v];	
	}
 
	else
	{
		root[r_u]=root[r_v];
		size[r_v]+=size[r_u];
	}
    
}
 
int main(void)
{
	ll x, y, ans=0;
	cin>>x>>y;
	ll q1, q2, q3, n=(x+y);
	for(int i=0; i<n; i++){ root[i]=i; size[i]=1; }
	ll u, v;
	cin>>q1;
	for(ll i=0; i<q1; i++){ cin>>u>>v; unionNodes(u-1, v-1); }
 
	cin>>q2;
	for(ll j=0; j<q2; j++){ cin>>u>>v; unionNodes(x+u-1, x+v-1); }
 
	cin>>q3;
	for(ll k=0; k<q3; k++){cin>>u>>v; unionNodes(u-1, x+v-1); }
 	
 	ll total[n][2];
 	memset(total, 0, sizeof(total));
	for(ll i=0; i<n; i++)
	{
		ll it=getroot(i);
		if(i<x) total[it][0]++;
		
		else total[it][1]++;
	}
		
	for(int i=0; i<n; i++)
		ans+=total[i][0]*( y-total[i][1] );

	cout<<ans<<"\n";
 
	return 0;
	
 
	
}