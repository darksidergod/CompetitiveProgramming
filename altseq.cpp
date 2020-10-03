#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main(void)
{
	ll n;
	cin>>n;
	ll a[n], seq[n];

	for(ll id=0; id<n; id++){ 
		cin>>a[id];
		seq[id]=1;
	}

	ll j=0;
	while(j<n)
	{	
		for(ll i=0; i<j; i++)
		{
			if(abs(a[j])>abs(a[i]) && ( (a[i]>0 && a[j]<0) || (a[i]<0 && a[j]>0) ) )
				seq[j]=max(seq[j], 1+seq[i]);
		}

		j++;
	}

	ll ans=0;
	for(ll i=0; i<n; i++)
	{
		if(ans<seq[i]) ans=seq[i];
	}
	cout<<ans<<"\n";
	return 0;
}