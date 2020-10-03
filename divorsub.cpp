#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define ull unsigned long long
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define F first
#define S second

int func(int k, int n)
{
    while((n%k)==0)
    {
        n=n/k;
    }

    return (n%k==1);
}

int32_t main(void)
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1; i*i<=(n-1); i++)
    {
        if((n-1)%i==0)
        {
            ans++;
            if(i!=n/i) ans++;
        }
    }

    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            ans+=func(i, n);
            if(i!=n/i) ans+=func(n/i, n);
        }
    }
    if(n==2) ans=1;
    
    cout<<ans<<"\n";
    return 0;
}
