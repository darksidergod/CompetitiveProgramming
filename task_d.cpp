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
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int32_t main(void)
{
    int n, k, ans=0;
    cin>>n>>k;
    flp(i, k, n+2)
    {
        int s1=(i*(i-1)/2)%mod;
        int m=(n-i);
        int s2=(n*(n+1)/2 - m*(m+1)/2%mod);
        ans=(ans+s2-s1+1)%mod;
    }
    cout<<ans<<"\n";
    return 0;
}