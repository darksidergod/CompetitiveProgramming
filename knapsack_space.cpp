#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(void)
{
	ll int N, W;
	cin>>N>>W;
	ll int w[N];
	ll int v[N];
	for(ll int i=0; i<N; i++)
		cin>>w[i]>>v[i];
	
	vector< pair<ll int, ll int> > items;

	for(ll int i=0; i<N; i++)
		items.push_back(make_pair(w[i], v[i]));

	sort( items.begin(), items.end() );

	vector< pair<ll int, ll int> >::iterator itr;
	
	
	
	return 0;
}