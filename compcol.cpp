#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define rev(i, k) for(int i=k; i>=0; i--)

#define F first
#define S second
int gcd(int a, int b)
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

int32_t main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, ct=0; cin>>n;
		int a[n], c[n];
		bool marked[n]={false};
		flp(i, 0, n) cin>>a[i];
		vector<int> v[11];
		map<int, int> mp;
		vector<int> prime={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
		vector<int> ans[11];
		flp(i, 0, n)
		{
			flp(k, 0, prime.size())
			{
				if(a[i]%prime[k]==0)
				{
					ans[k].pb(i);
					break;
				}
			}
		}
		int m=0;
		flp(k, 0, prime.size())
		{
			if(ans[k].size())
			{
				m++;
				flp(i, 0, ans[k].size())
				{
					c[ans[k][i]]=m;
				}
			}
		}
		
		cout<<m<<"\n";
		flp(i, 0, n)
		 cout<<c[i]<<" ";
		cout<<"\n";		
	}

	return 0;
}