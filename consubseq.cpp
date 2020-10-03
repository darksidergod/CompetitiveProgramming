#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
#define ft first
#define sd second 
#define vi vector<int>
int main(void)
{
	ll n; 
	cin>>n;
	ll a[n+1];
	for(ll id=1; id<n+1; id++)
		cin>>a[id];

	ll dp[n+1][2];
	map<ll, ll> mp;
	ll mlen=0, ind=1;
	for(ll i=1; i<n+1; i++)
	{
		if(mp[a[i]-1])
		{
			dp[i][0]=mp[a[i]-1];
			dp[i][1]=1+dp[(mp[a[i]-1])][1];
			if(dp[i][1]>mlen)
			{
				mlen=dp[i][1];
				ind=i;
			}
		}

		else
		{
			dp[i][0]=0;
			dp[i][1]=0;
		}

		if(!mp[a[i]])
			mp[a[i]]=i;

		else
		{
			if(dp[(mp[a[i]])][1]<dp[i][1])
				mp[a[i]]=i;
		}
	}
		cout<<mlen+1<<endl;
		vi ans;
		while(ind!=0)
		{
			ans.pb(ind);
			ind=dp[ind][0];
		}
		for(ll i=ans.size()-1;i>=0;i--)
			cout<<ans[i]<<" ";
	return 0;
}