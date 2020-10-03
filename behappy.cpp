#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
#define SIZE 100

ll power(ll a, ll b) {
ll x = 1, y = a;
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

ll totient(ll n) {
ll result = n;
for(ll i=2;i*i <= n;i++) 
{
    if (n % i == 0) result -= result / i;   
    while (n % i == 0) n /= i;
}

if (n > 1) result -= result / n;
return result;
}

ll l[SIZE], r[SIZE], m, n;

ll myfunc(ll box, ll N)
{
    ll ans=0;

    if(N<0 || N<l[box]) return 0;

    if(box==n-1)
    {
        if(N>=r[box] && N<=l[box]) return 1;
        
        else return 0;
    }

    for(int i=l[box]; i<=min(N,r[box]); i++)
        ans+=myfunc(box+1, N-i);
    
    return ans;    
}

int main(void)
{
    cin>>m>>n;
    for(int i=0; i<=m; i++)
        cin>>l[i]>>r[i];

    cout<<myfunc(0, n)<<"\n";
}