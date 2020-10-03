#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(void)
{
	ll int N, W, answer=-1;
	cin>>N>>W;
	ll int w[N+1];
	ll int v[N+1];
	w[0]=0;
	v[0]=0;

	for(ll int i=1; i<=N; i++)
		cin>>w[i]>>v[i];

	ll int dp[N+1][W+1];
	
	for(ll int j=0; j<=W; j++)
		dp[0][j]=0;

	for(ll int k=0; k<=N; k++)
		dp[k][0]=0;

	for(ll int item=1; item<=N; item++)
	{
		for(ll int weight=1; weight<=W; weight++)
		{
			if(w[item]>weight)
				dp[item][weight]=dp[item-1][weight];

			else
				dp[item][weight]=max(v[item]+dp[item-1][weight-w[item]],dp[item-1][weight]);
	
		}
	}

	cout<<dp[N][W]<<"\n";

	//cout<<answer<<"\n";
	return 0;
}
