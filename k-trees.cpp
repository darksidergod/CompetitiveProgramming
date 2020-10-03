#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define rev(i, k) for(int i=k; i>=0; i--)
#define F first
#define S second


int32_t main(void)
{
    int n, k, d;
    cin>>n>>k>>d;
    int dp[n+1][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0]=1;
    for(int x=0; x<=n; x++)
    {
        for(int y=1; y<=k && x+y<=n; y++)
        {
           // cout<<x<<" "<<y<<"\n";
            if(y>=d)
            {
                dp[x+y][1]=(dp[x+y][1]+dp[x][0])%mod;
                dp[x+y][1]=(dp[x+y][1]+dp[x][1])%mod;
            }

            else
            {
                dp[x+y][0]=(dp[x+y][0]+dp[x][0])%mod;
                dp[x+y][1]=(dp[x+y][1]+dp[x][1])%mod;
            }
        }
    }
   /* flp(i, 0, n+1)
    {
        cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    }*/
    cout<<dp[n][1]<<"\n";
    return 0;
}