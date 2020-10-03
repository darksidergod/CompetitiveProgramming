#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long

int main(void)
{
	ll n;
	cin>>n;
	ull a[n];
	ull b[n];
	for(ll i=0; i<n; i++) cin>>a[i];
			
	for(ll j=0; j<n; j++)
	{
		ull temp=a[j], cnt=0, tcnt=0;
		while(temp%2==0)
		{
			temp/=2;
			tcnt++;
		}

		if(tcnt>cnt)
	}
	
	cout<<x<<"\n";
	return 0;
	
}