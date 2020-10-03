#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define F first
#define S second

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

int32_t main(void)
{
    int n, m, k;
    cin>>n>>m>>k;
    int x, y;
    for(int i=0; i<n; i++)
     cin>>x>>y;
     
    

    for(int i=0; i<k; i++)
     cin>>x>>y;
    
    bool vis[n]={false};
    string s;
    for(int i=0; i<n-1; i++)
        s+='D';
    for(int j=0; j<m-1; j++)
        s+='L';

    for(int i=0; i<n; i++)
    {
        if(i%2==0)
            for(int j=0; j<m-1; j++) s+='R';

        else
            for(int j=0; j<m-1; j++) s+='L';
        
        if(i!=n-1) s+='U';
    }
    
    cout<<s.size()<<"\n";
    cout<<s<<"\n"; 
    return 0;
}