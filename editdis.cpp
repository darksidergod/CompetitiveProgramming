#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define F first
#define S second

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

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

int32_t main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        string a, b;
        cin>>a;
        cin>>b;
        int m=a.length();
        int n=b.length();
        int dp[n+1][m+1];
        dp[0][0]=0;
        flp(i, 1, n+1)    
            dp[i][0]=i;
        flp(i, 1, m+1)
            dp[0][i]=i;
        
        flp(i, 0, n)
        {
            flp(j, 0, m)
            {
                if(b[i]==a[j])
                    dp[i+1][j+1]=dp[i][j];
                
                else
                    dp[i+1][j+1]=1+min(dp[i][j], min(dp[i+1][j], dp[i][j+1]));
            }
            
        }
        /*flp(i, 0, n+1)
        {
            flp(j, 0, m+1)
            cout<<dp[i][j]<<" ";

            cout<<"\n";
        }*/
    cout<<dp[n][m]<<"\n";
    }

    return 0;
}