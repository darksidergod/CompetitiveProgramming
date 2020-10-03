#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define F first
#define S second

int32_t main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		int r, c;
		cin>>r>>c;
		if(r!=c)
		{
			cout<<51<<"\n";
			cout<<((r+c)/2)<<" "<<(r+c)/2<<"\n";
			cout<<1<<" "<<1<<"\n"; 
		}

		else if(r!=1 && c!=1)
		{
			cout<<50<<"\n";
			cout<<1<<" "<<1<<" ";
		}

		else
		{
			cout<<49<<"\n";
		}

		for(int i=1; i<=7; i++)
		{
			if((i+1)%2==0)
			{
				flp(j, 0, 7)
				{
					cout<<j+2<<" "<<((j+1)%2+1)+(i-1)<<"\n";
				}
			}

			else
			{
				flp(j, 0, 7)
				{
					cout<<7-j<<" "<<(i+(j+1)%2)<<"\n";
				}
			}
		}
	}

	return 0;
}