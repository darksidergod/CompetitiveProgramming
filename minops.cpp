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
#define SIZE 200

vector<int> grid[SIZE];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.S-p1.F)>(p2.S-p1.F);
}

int32_t main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        string s, r;
        vector<pair<int, int>> v;
        vector<int> dist;
        cin>>s; cin>>r;
        int n=s.size();
        flp(i, 0, n)
        {
            int j=0;
            if(s[i]==r[i])
            {
                j=i;
                while(s[j]==r[j] && j<n) j++;
                if(j==n) break;
                //cout<<i<<" "<<j-1<<"\n";
                if(i!=0 && j!=n) dist.pb(j-i);
                i=j;
            }
            if(j==n) break;
        }

        int ans=n;
        if(s[0]==r[0])
        {
            int k=1;
            while(s[k]==r[k]) k++;
            ans-=k;
        }

        if(s[n-1]==r[n-1] && ans>0)
        {
            int k=1;
            while(s[n-1-k]==r[n-1-k]) k++;
            ans-=k;
        } 

        sort(dist.begin(), dist.end());
        reverse(dist.begin(), dist.end());
        int k=1, len=ans;
        for(auto i:dist)
        {
            k++;
            len-=i;
            ans=min(ans, k*len);
        }
        cout<<ans<<"\n";
    }
    return 0;
}