#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define SIZE (ll)5e6
ll n, a[SIZE];

void func(ll key)
{
	ll lo=0, hi=n-1, mid=lo+(hi-lo)/2;
	if(a[hi]<key){ cout<<0<<"\n"; return;}
	if(a[lo]>=key){ cout<<n<<"\n"; return;}
	while(lo<hi)
	{
		mid = lo + (hi-lo)/2;

		if(a[mid]<key) lo=mid+1;

		else hi=mid;
	}

	if(a[lo]>=key) { cout<<n-lo<<"\n";}

	else if(a[mid]>=key) { cout<<n-mid<<"\n";}

	else if(a[hi]>=key) { cout<<n-hi<<"\n";}

	return;
}

int main(void)
{
	ll m, q;
	cin>>n;
	cin>>m;	
	memset(a, 0, sizeof(a));
	
	for(ll i=0; i<m; i++)
	{
		ll u, v;
		cin>>u>>v;
		u--; v;
		a[u]++;
		if(v<n) a[v]--;
	}

	for(ll i=1; i<n; i++)
		a[i]+=a[i-1];
	sort(a, a+n);
	cin>>q;
	for(ll id=0; id<q; id++)
	{
		ll x, ans;
		cin>>x;
		func(x);
	}
	
	return 0;

}
