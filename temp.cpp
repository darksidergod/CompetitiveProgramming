#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
ll power(ll a, ll b) {
ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}
#define SIZE 1000000

ll d[SIZE];
bool white[SIZE];
vector<ll> adj[SIZE];

 
 
void go(int v, int prev = -1)
{
	d[v] = white[v];
	for(int i=0; i<(int)adj[v].size(); i++)
	{
		int to = adj[v][i];
 
		if (prev == to)
			continue;
		go(to, v);
		d[v] += d[to];
	}	
}

int main(void)
{
	memset(white, 0, sizeof(white));
	//memset(vis, 0, sizeof(vis));
	int n; cin>>n;
	vector<int> ans;
	for(int i=0; i<n-1; i++)
	{
		int u, v, t;
		cin>>u>>v>>t;
		adj[u].pb(v); adj[v].pb(u);
		white[u]=t-1; white[v]=t-1;
	}

	go(1);
	for(int i=1; i<=n; i++)
	{
		if(d[i]==1 && white[i]) 
		 ans.pb(i);
	}

	cout<<ans.size()<<"\n";
	for(auto i:ans)
		cout<<i<<" ";	
	cout<<"\n";
	return 0;
}