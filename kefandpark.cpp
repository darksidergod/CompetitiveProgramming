#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
#define SIZE 100002

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

vector<ll> adj[SIZE];
bool visited[SIZE];
int cats[SIZE], ans, m;

void dfs(int r, int catcount)
{
		if(cats[r]) catcount++;
		else catcount=0;
		if(catcount<=m){
				if(r>1 && adj[r].size()==1 && catcount<=m) ans++; 
				visited[r]=true;
				for(int i=0; i<adj[r].size(); i++)
				{
						if(!visited[adj[r][i]])
							{
								dfs(adj[r][i], catcount);
							} 
				}
				}
}

int main(void){
	int n;
	cin>>n>>m;
	memset(visited, 0, sizeof(visited));
	for(int i=1; i<=n; i++) cin>>cats[i];
	
	for(int i=0; i<n-1; i++)
	{
		int u, v; cin>>u>>v;
		adj[u].pb(v); adj[v].pb(u);
	}
	int ct=0;
	dfs(1, ct);	
	cout<<ans<<"\n";
	return 0;
}