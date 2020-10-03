#include <bits/stdc++.h>

#define ll long long
#define M 1000000007
using namespace std;
ll n,m,nCr[1001][1001],ans=1,s[1001],p[1001];

int main(){
    cin >> n >> m;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0 || j==i) 
            	nCr[i][j]=1;
            else 
            	nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%M;
        }
    }
    p[0]=1;p[1]=1;
    for(int i=2;i<=n;i++) 
    	p[i]=(p[i-1]*2)%M;

    for(int i=0;i<m;i++) 
    	cin>>s[i];
    
    sort(s,s+m);
    ll cur=0,tmp;
    
    for(int i=0;i<m;i++)
    {
        if(i==0) 
        	tmp=s[i]-1;
        
        else
        {
            tmp=s[i]-s[i-1]-1;
            ans=(ans*p[tmp])%M;
        }
        cur+=tmp;
        ans=(ans*nCr[cur][tmp])%M;
    }
    cur+=n-s[m-1];
    ans=ans*nCr[cur][n-s[m-1]]%M;
    cout << ans << endl;
    return 0;
}