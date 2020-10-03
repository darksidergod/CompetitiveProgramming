#include <bits/stdc++.h>

using namespace std;

int vacation[100001][3];
int answer[100001][2];

int main(void)
{
	int n;
	cin>>n;
	int a[n], b[n], c[n];

	for(int i=0; i<n; i++)
		cin>>a[i]>>b[i]>>c[i];

	int dp[n][3];
	dp[0][0]=a[0];
	dp[0][1]=b[0];
	dp[0][2]=c[0];

	for(int i=1; i<n; i++)
	{
		dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
		dp[i][1]=b[i]+max(dp[i-1][0], dp[i-1][2]);
		dp[i][2]=c[i]+max(dp[i-1][0], dp[i-1][1]);
	}

	int result;
	result = max(dp[n-1][0],dp[n-1][1]);
	result = max(dp[n-1][2], result);
	cout<<result<<"\n";
}