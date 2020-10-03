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
#define SIZE (int)(6e5)
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int spf[SIZE];
bool prime[SIZE];

void sieve()
{   
    spf[1]=1;
    for(int i=2; i<SIZE; i++)
    {
        prime[i]=true;
        spf[i]=i;
    }
    for(int i=2; i*i<SIZE; i++)
    {
        if(prime[i])
        {
            for(int j=i*i; j<SIZE; j+=i)
             {
                prime[j]=false;
                if(spf[j]==j) 
                 spf[j]=i;
             }
         }
    }
}

int32_t main(void)
{
    sieve();
    int n;
    cin>>n;
    //int a[n];
    //flp(i, 0, n) cin>>a[i];
    vector<pair<int, int>> d;
    d.pb({1, 1});
    for(int i=2; i<=n; i++)
        d.pb({i/spf[i], i});
    sort(d.begin(), d.end());
    flp(i, 1, n)
    {
        cout<<d[i].F<<" ";
    }
    cout<<"\n";
    return 0;    
}