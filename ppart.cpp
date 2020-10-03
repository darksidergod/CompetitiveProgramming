#include <bits/stdc++.h>
using namespace std;
#define mod 998244353 
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define rev(i, k) for(int i=k; i>=0; i--)
#define F first
#define S second

int32_t main(void)
{
    int N, K, ans=1, sum=0, p=-1;
    cin>>N>>K;
    int a[N];
    flp(i, 0, N) cin>>a[i];
    
    flp(i, 0, N)
    {
        if(a[i]>=(N-(K-1)))
        {
            if(ans!=-1)
            {
                if(p!=-1)
                 ans=ans*(i-p)%mod;
                
                sum+=a[i];
                p=i;
            }
        }

    }

    cout<<sum<<" "<<ans<<"\n";
    return 0;
}
