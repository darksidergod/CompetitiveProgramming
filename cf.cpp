#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair

int power(int a, int b) {
int x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}

int totient(int n) {
int result = n;
for(int i=2;i*i <= n;i++) 
{
    if (n % i == 0) result -= result / i;   
    while (n % i == 0) n /= i;
}

if (n > 1) result -= result / n;
return result;
}

int dp[n][2][2];

int myfunc(int i, int x, int y )
{
	

}
int32_t main(void)
{
    int t; cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n; int a[n];
    	for(int i=0; i<n; i++)
    		cin>>a[i];
    	
    	for(int i=0; i<n; i++)
    	{
    		if(i==0 && a[i]>0)
    		{	
    			if(a[0]<a[1])
    				a[0]=(-a[0]);
    		}

    		if(i==(n-1) && a[i]>0)
    		{
    			if(a[n-1]<a[n-2])
    				a[n-1]=a[n-1]*(-1LL);
    		}

    		if(a[i]<a[i-1] && a[i]<a[i+1] && a[i]>0 && (a[i-2]+a[i-1]-a[i])>0)
    			a[i]=a[i]*(-1LL);		
       	}

       	for(int i=0; i<n; i++)
       		cout<<a[i]<<" ";
       	cout<<"\n";
    }
    return 0;
}