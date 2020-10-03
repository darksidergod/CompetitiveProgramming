Copy
#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
using namespace std;
 
int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n, g, b;
		cin>>n>>g>>b;
		ll ans=0, target=(n+1)/2;
		if((n+1)/2<=g || b==0)
			ans=n;
 
		else
		{
			ll m = (target+(g-1))/g;
			target=(target - g*(m-1));
			if(g>1)
				ans=(((g+b)*(m-1)) +(target%g));
			else
				ans=(((g+b)*(m-1)) +(g));
			if(ans<n)
			 ans=n;	
		}
 
		cout<<ans<<"\n";
	}
	return 0;
}