#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		ll int n, lcmofnums=0, gcdofnums;
		cin>>n;
		ll int a[n];
		for(ll int i=0LL; i<n; i++)
			cin>>a[i];
		
		sort(a, a+n);
		cout<<a[0]<<"\n";

	}
	return 0;
}