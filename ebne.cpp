#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	// your code goes hee
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		string s;
		cin>>s;
		for(ll i=n-1;i>-1;i--)
		{
			if((s[i]-'0')%2==0)
			{
				s.erase(s.begin()+i);
			}
		}
		n=s.size();
		if(n==0)
		{
			cout<<"-1\n";
			continue;
		}
		ll sum=0;
		n=s.size();
		ll od=0;
		for(ll i=0;i<n;i++)
		{
			sum+=s[i]-'0';
			if((s[i]-'0')%2)
			{
				od++;
			}
		}
		if(sum%2==0)
		{
			cout<<s<<"\n";
			continue;
		}
		if(od==1)
		{
			cout<<"-1\n";
			continue;
		}
		ll tr=1;
		for(ll i=0;i<n;i++)
		{
			if((s[i]-'0')%2==0 || tr==0)
			{
				cout<<s[i];
			}
			else
			{
				tr=0;
			}
		}
		cout<<"\n";
		
	}
	return 0;
}