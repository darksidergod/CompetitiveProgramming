#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll n, c;

bool myfunc(ll* pos, ll dis)
{
	ll i, cnt=1, last=pos[0];
	for(int i=1; i<n; i++)
	{
		if((pos[i]-last)>=dis)
		{
			cnt++;
			if(cnt==c) return true;
			last=pos[i];
		}
	}

	return false;

}

int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		ll v[n], ans=-1;
		for(int i=0; i<n; i++) 
			cin>>v[i];
		sort(v, v+n);
		ll lo=0, hi=v[n-1], mid;
		while(lo<hi)
		{
			mid = lo + (hi-lo)/2;
		
			if(myfunc(v, mid)) {
				if(mid>ans) ans=mid;

					lo=mid+1;}

			else hi = mid; 
		}

		cout<<ans<<"\n";
	}

	return 0;
}