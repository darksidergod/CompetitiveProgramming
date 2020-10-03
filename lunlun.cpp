#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define F first
#define S second

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int32_t main(void)
{
    int k; cin>>k;
    queue<int> q;
    flp(i, 1, 10) q.push(i);
    int ans;
    flp(i, 0, k)
    {
        ans=q.front();
        q.pop();
        if(ans%10!=0) q.push(10*ans +(ans%10)-1);
        q.push(ans*10 + (ans%10));
        if(ans%10!=9) q.push(10*ans+(ans%10)+1);
    }

    cout<<ans<<"\n";
    return 0;
}