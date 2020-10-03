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
const int N = 300000 + 300;

int white[N], d[N];
vector<int> adj[N];
vector<int> ans;

void func(int v, int prev)
{
	d[v] = 0;
	if(white[v]) d[v]+=1;

	for(int i=0; i<(int)adj[v].size(); i++)
	{
		int u = adj[v][i];
 
		if (prev == u) continue;
		func(u, v);
		d[v] += d[u];
	}	
}

int main(void)
{
	//memset(fault, 0, sizeof(fault));
	//memset(vis, 0, sizeof(vis));
	int n;
	cin>>n;
	for(int i=0; i<n-1; i++)
	{
		int u, v, t;
		cin>>u>>v>>t;
		u--; v--;
		adj[u].pb(v); adj[v].pb(u);
		if(t==2)
		{
			white[u]=1;
			white[v]=1;
		}
	}
	func(0, -1);
	for(int i=1; i<=n; i++)
	{
		if(white[i] && d[i]==1)
			ans.pb(i+1);
	}
	cout<<ans.size()<<"\n";
	if(ans.size()>0)
		{
			for(auto i:ans)
				cout<<i<<" ";	
		cout<<"\n";
		}
	return 0;
}