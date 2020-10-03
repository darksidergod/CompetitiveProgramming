#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mk make_pair
#define SIZE 1000004
int mod=1000000007;
int dp[SIZE][3], a[SIZE];

int32_t main(void)
{
	memset(a, 0, sizeof(a));
	int t;
	cin>>t; 
	while(t--)
	{
		string s;
		cin>>s;
		for(int i=0; i<(int)(s.length());i++)
			a[i+1]=s[i]-'0';
		dp[0][0]=1;
		dp[0][1]=0;
		dp[0][2]=0;

		int res=0, n=(int)(s.length());
		for(int i=1; i<n+1; i++)
		{
			for(int j=0; j<3; j++)
					dp[i][j] = (dp[i-1][j] + dp[i-1][(j-(a[i]%3)+3)%3])%mod;
					
			if(a[i]%2==0) res=(res+dp[i-1][(3-(a[i]%3))%3])%mod;
		} 
		cout<<res<<"\n";

	}

	return 0;
}