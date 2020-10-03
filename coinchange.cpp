#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define F first
#define S second
#define SIZE 10000

int dp[SIZE][SIZE];

int32_t main(void)
{
    int sum, n;
    cin>>sum>>n;
    int dp[n+1][sum+1];
    memset(dp, 0, sizeof(dp));
    int c[n+1]; 
    flp(i, 1, n+1) cin>>c[i];

    dp[0][0]=1;
    flp(i, 1, sum+1) dp[0][i]=0;
    flp(i, 1, n+1) dp[i][0]=1;

    flp(i, 1, n+1){
        flp(j, 1, sum+1){
            dp[i][j]+=dp[i-1][j];
            if(j-c[i]>=0) dp[i][j]+=dp[i][j-c[i]];
        }
    }

    
    cout<<dp[n][sum]<<"\n";
    return 0;

}

