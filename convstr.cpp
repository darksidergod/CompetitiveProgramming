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

void solve()
{
    int n; cin>>n;
    string a, b; cin>>a>>b;
    vector< vector<int> > ans;
    flp(i, 0, n) 
    {
        if(a[i]<b[i])
        {
            cout<<-1<<"\n";
            return;
        }
    }

    for(char c='z'; c>='a'; c--)
    {
        vector<int> pos;
        bool f=false;

        flp(i, 0, n)
        {
            if(b[i]==c && a[i]!=b[i]) 
             pos.pb(i);
        }

        if(!f && !pos.empty())
        {
            flp(i, 0, n)
            {
                if(a[i]==c)
                {
                    f=true;
                    pos.pb(i);
                }
            }
        }

        if(!f && !pos.empty())
        {
            cout<<-1<<"\n";
            return;
        }

        if(!pos.empty()) ans.pb(pos);
        for(int i:pos) a[i]=c;
    }

    cout<<ans.size()<<"\n";
    for(auto x:ans)
    {
        cout<<x.size()<<" ";
        for(auto y:x) cout<<y<<" ";
        cout<<"\n";
    }
    
}

int32_t main(void)
{
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}





