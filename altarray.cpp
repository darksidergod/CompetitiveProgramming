#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, n) for(int i=0; i<n; i++)

int power(int a, int b) {
int x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}

int totient(int n) {
int result = n;
for(int i=2;i*i <= n;i++) 
{
    if (n % i == 0) result -= result / i;   
    while (n % i == 0) n /= i;
}

if (n > 1) result -= result / n;
return result;
}

int32_t main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; 
        cin>>n;
        int a[n];
        flp(i, n) cin>>a[i];
        int dp[n];
        flp(i, n) dp[i]=1;
        for(int i=n-2; i>=0; i--)
        {
            if( (a[i]>0 && a[i+1]<0) || (a[i]<0 && a[i+1]>0) )
                dp[i]+=dp[i+1];      
        }

        flp(i, n) cout<<dp[i]<<" ";
        cout<<"\n";
    }
    return 0;
}