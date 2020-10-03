#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void)
{
	ll int n, k, cost=0;
	cin >>n >> k;
	ll int h[n];
	for(int i=0; i<n; i++)
		cin>>h[i];

	long long int dp[n];
	dp[0]=0;
	dp[1]=abs(h[1]-h[0]);
	for(int i=2; i<n; i++)
		dp[i]=INT_MAX;


	for(ll int i=2; i<n; i++)
	{
		for(int j=1; j<=k && i-j>=0; j++)
		{
			cost=dp[i-j]+abs(h[i]-h[i-j]);
			if(cost<dp[i])
				dp[i]=cost;
		}
	}
	

	cout<<dp[n-1]<<"\n";
	return 0;
}