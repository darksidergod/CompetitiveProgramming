#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll int maxDivisor(ll int n) 
{ 
	ll int _max
    // Note that this loop runs till square root 
    for (ll int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                {
                	if(i>=_max)
                		_max=i;
                } 
  
            else // Otherwise print both 
                {
                	if(i>=_max && i!=n)
                		_max=i;

                	if((n/i)>=_max && (n/i)!=n)
                		_max=(n/i);

                } 
        } 
    } 

    return _max;
} 

int main(void)
{
	ll int n;
	cin >> n;
	ll int res=maxDivisor(n);
	cout << res <<"\n";
	return 0;
}