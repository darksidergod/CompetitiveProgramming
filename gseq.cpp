#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main(void)
{
	ll n, k, ans=0;
	cin>>n>>k;
	ll a[n], seq[n];
	for(ll id=0; id<n; id++)
		cin>>a[id];
	
	if(k!=1)	
	{
		for(int id=0; id<n; id++)
		{
			multiset<ll> ms;
			for(int j=id+1; j<n; j++) ms.insert(a[j]);
			ll temp=1;
			temp*=ms.count(a[id]*k);
			temp*=ms.count(a[id]*k*k);
			cout<<temp<<"\n";
			ans+=temp;
		}
	}

	cout<<ans<<"\n";
	return 0;
}