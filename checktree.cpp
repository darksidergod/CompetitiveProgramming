	#include <bits/stdc++.h>

	using namespace std;

	int main(void)
	{
		int n, edges=0, temp;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			cin>>temp;
			edges+=temp;
		}

		edges/=2;
		if((edges+1)==n)
			cout<<"Yes\n";
		else
			cout<<"No\n";

		return 0;
	}