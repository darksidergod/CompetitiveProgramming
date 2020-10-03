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
		int n, k=-1;
		cin>>n;
		int a[n]; set<int> s;
 		flp(i, 0, n)
		{
			cin>>a[i];
			s.insert(a[i]);
		}

		if(s.size()==1 || s.size()==2)
		{
			cout<<s.size()<<"\n";
			flp(i, 0, n){
				if(a[i]==a[0])
					cout<<1<<" ";
				else
					cout<<2<<" ";
			} 
			cout<<"\n";
		}

		else if(n%2==0)
		{
			cout<<2<<"\n";
			flp(i, 0, n)
			 cout<<i%2+1<<" ";
			cout<<"\n";
		}

		else
		{
			bool flag=false;

			flp(i, 0, n)
			{
				if(a[i]==a[(i+1)%n])
				{
					k=i; flag=true;
					break;
				}
			}

			if(!flag)
			{
				cout<<3<<"\n";
				flp(i, 0, n-1)
				 cout<< i%2+1<<" ";
				cout<<3<<"\n";
			}

			else
			{
				int ans[n];
				for(int j=0, i=k+1; i<n; i++, j^=1)
					ans[i]=j+1;
				
				for(int j=0, i=k; i>=0; i--, j^=1)
					ans[i]=j+1;

				cout<<2<<"\n";
				flp(i, 0, n)
				 cout<<ans[i]<<" ";
				cout<<"\n";
			}
		}
	}

	return 0;
}