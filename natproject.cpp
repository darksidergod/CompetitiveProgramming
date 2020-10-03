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
		ans=(target/g)*(g+b);
		if(target%g>0)
			ans+=target%g;
		else
			ans-=b;
		
		ans=max(n, ans);
		cout<<ans<<"\n";
	}
	return 0;
}