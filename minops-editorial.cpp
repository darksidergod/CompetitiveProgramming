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
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

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


int32_t main(void)
{
    int t; cin>>t;
    while(t--)
    {
        string s, r;
        cin>>s>>r;
        int n=s.size();
        int fst=0, len=0, k=0;
        vector<int> dist;
        bool flag=false;
        flp(i, 0, n)
        {
            if(s[i]==r[i])
            {
                if(flag) fst++;
            }

            else
            {
                if(!flag) k++;
                flag=true;
                len++;
                if(fst>0)
                {
                    k++;
                    dist.pb(fst);
                    fst=0;
                }
            }
        }
        sort(dist.begin(), dist.end());
        int ans=k*len;
        for(auto i:dist)
        {
            len+=i;
            k--;
            ans=min(ans, len*k);
        }

        cout<<ans<<"\n";
    }
}