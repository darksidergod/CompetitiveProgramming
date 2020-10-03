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
    int t;
    cin>>t;
    while(t--)
    {
        int n, x;
        cin>>n>>x;
        int a[n];
        flp(i, 0, n) cin>>a[i];
        sort(a, a+n);
        
        int ans=0, ct=0;
        for(int i=n-1; i>=0; i--)
        {
            if(ans+a[i]>=(x)*(n-i))
            {
                ans+=a[i];
                ct=(n-i);
            }

            else
            {
                break;
            }
            
        }
        cout<<ct<<"\n";
    }
    return 0;
}