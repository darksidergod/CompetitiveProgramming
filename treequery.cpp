#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define vll vector<long long int> 
#define ii pair<long long int, long long int>

vll adj1[100000];
vll adj2[100000];

int main(void)
{
	ll n, e, sinknodes1=0, sinknodes2=0;
	cin>>n>>e;
	for(int i=0; i<e; i++)
	{
		ll u, v;
		cin>>u>>v;
		adj1[u].push_back(v);
		adj2[v].push_back(u);
	}

	for(ll i=1;i<=n; i++)
	{
		if((ll)adj1[i].size()==0)
			sinknodes1++;
		
		if((ll)adj2[i].size()==0)
			sinknodes2++;
	}

	cout<<max(sinknodes1, sinknodes2)<<"\n";
	return 0;
}