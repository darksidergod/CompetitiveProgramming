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
    int n, m, k;
    cin>>n>>m>>k;
    int sum1[n+1]={0}, sum2[m+1]={0};
    int x, y=0;
    flp(i, 0, n)
    {
        cin>>x;
        if(x==0) y=0;
        else y++;
        sum1[y]++;
    }
    y=0;
    flp(i, 0, m)
    {
        cin>>x;
        if(x==0) y=0;
        else y++;
        sum2[y]++;
    }
    for(int i=n; i>=2; i--)
     sum1[i-1]+=sum1[i];
    
    for(int i=m; i>=2; i--)
     sum2[i-1]+=sum2[i];

    int ans=0;

    for(int i=1; i*i<=k; i++)
    {
        if(k%i==0)
        {
           if(i<=n && k/i<=m) ans+=sum1[i]*sum2[k/i];
           if(i!=k/i && i<=m && k/i<=n) ans+=sum1[k/i]*sum2[i];
        }   
    }
    cout<<ans<<"\n";

    return 0;

}