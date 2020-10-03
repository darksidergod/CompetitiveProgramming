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

int main(void)
{
	ll n;
	cin>>n;
	ll a[n], seq[n];
	for(ll i=0; i<n; i++){ 
			cin>>a[i];
			seq[i]=1;
		}

	vector<ll> v; v.pb(a[0]);
	ll len=1;
	for(int i=1; i<n; i++)
	{
		if(a[i]<v[0])
		{
			v.clear(); 
			v.pb(a[i]); 

		}

		else if(a[i]>v[len-1])
		{
			len++;
			v.pb(a[i]); 
		}

		else
		{
			ll index = lower_bound(v.begin(), v.end(), a[i])-v.begin();
			v[index]=a[i];
		}
		
	}

	cout<<len<<"\n";
	vector<ll>::iterator i;
	i=v.end(); i--;

	ll s=(*i)-v.size()+1;
	for(int i=0; i<n; i++)
	{
		if(s==a[i])
		{
			cout<<i+1<<" ";
			s++;
		}
	}
	cout<<"\n";
	return 0;
}