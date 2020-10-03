#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mk make_pair
const ll mod=1LL<<32;
const ll size=1e9+1;
int main(void)
{
    bitset<size> bs;
    ll q, s1, a, b, sum=0;
    cin>>q>>s1>>a>>b;
    for(ll id=0; id<q; id++)
    {
        if(s1%2==0)
        {
            if(bs[(int)(s1/2)])
            {
                bs[(int)(s1/2)]=0;
                sum-=s1/2;
                
            }
        }
        
        else
        {
            if(!bs[(int)s1/2])
            {
                bs[(int)(s1/2)]=1;
                sum+=s1/2;
            }
        }
        
        s1=(s1*a+b)%mod;
    }
    
    cout<<sum<<"\n";
    return 0;
}