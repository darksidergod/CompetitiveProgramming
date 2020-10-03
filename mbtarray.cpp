#include <bits/stdc++.h>

#define ll long long int 
#define vi vector<int>
#define ii pair<int, int>

using namespace std;

bool visited[1001];
bool adj[26][26];
vector<int> ans;

ll dfs(ll u)
{
	stack<ll> s;
	s.push(u);
	visited[u]=true;
	ll ans=1;

	while(!s.empty())
	{
		ll v=s.top();
		s.pop();
		for(ll i=0; j<=26; j++)
		{
			if(adj[v][j])
			{
				if(!visited[j])
					s.push(j);
			}
		}

		if(!visited[v])
			ans.pb(v);

		visited[v]=1;
	}
}	

int main(void){
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n=s.length();
		for(int i=0; i<n-1; i++)
		{
			if(s[i]!=s[i+1])
			{
				int x=s[i]-'a';
				cout<<x<<"\n";
			}
		}
	}

}