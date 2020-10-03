#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define rev(i, k) for(int i=k; i>=0; i--)
#define F first
#define S second
#define pi pair<int, int>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define SIZE (int)(6e5)
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
#define SIZE 10000

int32_t main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, x;
        cin>>n>>x;
        int ct[n];
        memset(ct, 0, sizeof(ct));
        x--;
        flp(i, 1, n)
        {
            int u, v;
            cin>>u>>v;
            u--;v--;
            ct[u]++;
            ct[v]++;
        }
        set<int> v;
        flp(i, 0, n)
        {
            if(ct[i]==1) 
             v.pb(i);
        }
        int turn=0;
        flp(i, 0, n)
        {
            auto it=v.find(x);
            if(it!=v.end())
            {
                break;
            }
            

        }
        
    }
}