#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll int v[1000000];
ll int w[1000000];

long long int KS(ll int n, ll int c)
{
	ll int result, temp1, temp2;
	if(n==0 || c==0)
		result=0;

	else if(w[n-1]>c)
		result=KS(n-1, c);

	else
	{
		temp1 = v[n-1]+KS(n-1, c-w[n-1]);
		temp2 = KS(n-1, c);
		result = max(temp1, temp2);
	}

	return result;
}

int main(void)
{
	ll int n, capacity;
	cin>>n>>capacity;
	
	for(ll int i=0; i<n; i++)
		{
			cin>>w[i];
			cin>>v[i];
		}

	ll int answer;
	answer=KS(n, capacity); 
	cout<<answer<<"\n";
	return 0;
	

}