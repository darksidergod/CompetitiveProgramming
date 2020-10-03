#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll int maxcustom(ll int a, ll int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

ll int mincustom(ll int a, ll int b)
{
	if(a<=b)
		return a;
	else
		return b;
}

int main(void)
{
	ll int n, cost=0;
	cin >>n;
	ll int h[n];
	for(int i=0; i<n; i++)
		cin>>h[i];

	long long int dp[n];
	for(int i=0; i<n; i++)
		dp[i]=0;

	dp[1]=abs(h[1]-h[0]);

	for(ll int i=2; i<n; i++)
		 dp[i]=min( dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]) );
	

	cout<<dp[n-1]<<"\n";
	return 0;
}