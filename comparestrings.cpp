#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(void)
{
	ll a, b;
	cin>>a>>b;
	string acon, bcon;
	acon=a+48;
	bcon=b+48;
	for(int i=1; i<b; i++)
		acon+=(a+48);

	for(int i=1; i<a; i++)
		bcon+=(b+48);

	if(acon>bcon)
		cout<<bcon<<"\n";

	else
		cout<<acon<<"\n";

	return 0;	
}