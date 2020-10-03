#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
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

int main(void)
{
    ll a, b, c, ans=0;
    cin>>a>>b>>c;
    ll oa=a, ob=b, oc=c;

    if(a%3==0 && b%3==0 && c%3==0) ans=(a+b+c)/3;
    else
    {
        ans+= a/3 + b/3 + c/3;
        a=a%3; b=b%3; c=c%3;
        ll x=min(a, min(b,c)); ans+=x;
        a-=x; b-=x; c-=x;
        if(a+b+c>=4 && oa>0 && ob>0 && oc>0) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}