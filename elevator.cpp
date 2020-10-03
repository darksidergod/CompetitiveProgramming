#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, n) for(int i=0; i<n; i++)
#define F first
#define S second
#define SIZE 1000000
int n, u, d;
bool vis[SIZE]={false};
int level[SIZE]={0};

void bfs(int r)
{
	queue<int> q;
	q.push(r);
	vis[r]=true;
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
	//	cout<<"for "<<v<<"\n";
	//	cout<<v-d<<"\n";
	//	cout<<v+u<<"\n";
		if(v-d>=0)
		{
			if(!vis[v-d]){ 
				q.push(v-d);
				vis[v-d]=true;
				level[v-d]=1+level[v];
			}
		}

		if(v+u<n)
		{
			if(!vis[v+u]){
				q.push(v+u);
				vis[v+u]=true;
				level[v+u]=1+level[v];
			}
		}
	}

}


int32_t main(void)
{
	int s, t;
	cin>>n>>s>>t>>u>>d;
	s--; t--;
	bfs(s);
	if(s==t) cout<<0<<"\n";
	else if(vis[t]) cout<<level[t]<<"\n";
	else cout<<"use the stairs\n";
	//flp(i, n) cout<<vis[i]<<" ";
	//cout<<"\n";
	return 0;
	
	
}