#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define SIZE 1000
#define pb push_back
ll dp[SIZE+1][SIZE+1];
ll a[SIZE], b[SIZE];

int main(void)
{
	memset(dp, 0, sizeof(dp));
	ll n, m;
	vector<ll> ans;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int j=0; j<n; j++)
		cin>>b[j];

	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=m; j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;

			else if(a[i-1]==b[j-1])
				dp[i][j]=1+dp[i-1][j-1];

			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}

	int i=n, j=m;
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			ans.insert(ans.begin(), a[i-1]);
			i--; j--;
		}

		else if(dp[i-1][j]>dp[i][j-1]) i--;
		
		else j--;
	}
	for(auto i: ans)
		cout<<i<<" ";
	cout<<"\n";
	return 0;
	
}