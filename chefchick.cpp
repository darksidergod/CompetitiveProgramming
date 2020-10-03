#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll int eugcd(ll int m, ll int n)
{
	ll int t;
	while(n!=0)
	{
 		t=m%n;
 		m=n;
 		n=t;
	}
	return m;
}

int main(void)
{
	ll int t;
	cin>>t;
	for(ll int x=0; x<t; x++)
	{
		ll int n, upper_lim, pen_upper_lim=0LL, ans=0, min_elem=INT_MAX;
		cin>>n;
		ll int a[n];
		for(ll int i=0; i<n; i++)
			{
				cin>>a[i];
				if(min_elem>a[i])
					min_elem=a[i];
			}
		
		ll int temp=a[0];
		for(ll int i=1; i<n; i++)
		{
			ll int ans_gcd;
			if(temp>a[i])
				ans_gcd=__gcd(temp, a[i]);

			else
				ans_gcd=__gcd(a[i], temp);

			upper_lim=(temp*a[i]/ans_gcd);
			temp=upper_lim;
		}

		//cout<<upper_lim<<"\n";
		pen_upper_lim=( (upper_lim/min_elem) - 1 )*min_elem;
		//cout<<pen_upper_lim<<"\n";
		if(ans<(upper_lim-pen_upper_lim))
			ans=(upper_lim-pen_upper_lim);

		cout<<ans<<"\n";

	}
	return 0;
}
