#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(void)
{
	ll int t;
	cin>>t;
	while(t--)
	{
		ll int a, b, n, ans=0;
		cin>>a>>b;

		if(a<b)
			n=(b-a);
		else
			n=(a-b);
	
		for(ll int i=1; i*i<=n; i++)
		{
			if((n%i)==0)
			{
				if(i!=(n/i))
					ans+=2;

				else
					ans+=1;
			}
		}
		

		cout<<ans<<"\n";
	}
	return 0;

}