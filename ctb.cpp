#include <bits/stdc++.h>
using namespace std;
#define mod 998244353 
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, n) for(int i=0; i<n; i++)
#define F first
#define S second

int mul(const int v1, const int v2, int mod=MOD) {
    return (int)((1LL * v1 * v2) % mod);
}
 
int toPower(int a, int p, int mod=MOD) {
    int res = 1;
    while (p != 0) {
        if (p & 1)
            res = mul(res, a, mod);
        p >>= 1;
        a = mul(a, a, mod);
    }
    return res;
}
 
int pl(int v1, int v2, int mod=MOD) {
    int res = v1 + v2;
 
    if (res < 0)
        res += mod;
 
    else if(res>=mod)
        res-=mod;
 
    return res;
}

int32_t main(void)
{
    int n; cin>>n;
    int dp[n+1]; 
    memset(dp, 0, sizeof(dp));
    dp[n]=10;
    int sum1=0, sum2=0; 
    for(int i=1; i<=n; i++)
    {
       
    }

    for(int i=n; i>=1; i--  )
        cout<<dp[i]<<" ";

    cout<<"\n";
    return 0;
}