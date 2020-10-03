#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define F first
#define S second
#define SIZE 1000000
// /int mod = 1000000007;
int root[SIZE], size[SIZE];

int getroot(int x)
{
	if(x != root[x]) {
		root[x] = getroot(root[x]);
	}
	return root[x];
}
 
void unionNodes(int u, int v)
{
	int r_u=getroot(u);
	int r_v=getroot(v);
	if(r_u==r_v) return;
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

int32_t main(void)
{
	int n, p;
	cin>>n>>p;
	flp(i, 0, n)
	{
		root[i]=i;
		size[i]=1;
	}

	flp(i, 0, p)
	{
		int u, v;
		cin>>u>>v;
		unionNodes(u, v);
	}

	vector<int> ans;
	bool vis[n]={false};
	flp(i, 0, n)
	{
		int x=getroot(i);
		if(!vis[x])
		{
			vis[x]=true;
			ans.pb(size[x]);
		}
	}
	int res=0, sum=n;
	sort(ans.begin(), ans.end());
	flp(i, 0, n)
	{
		sum-=size[i];
		res+=size[i]*(sum);	
	}


	//cout<<temp<<"\n";
	cout<<res<<"\n";
	return 0;

}