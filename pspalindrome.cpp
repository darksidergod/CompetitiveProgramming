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

int func(string s){
    string kmprev = s;
    std::reverse(kmprev.begin(), kmprev.end());
    string kmp = s + "#" + kmprev;
    vector<int> lps(kmp.size(), 0); 
    for (int i = 1; i < (int)lps.size(); ++i)
    {
        int prev_idx = lps[i - 1];
        while (prev_idx > 0 && kmp[i] != kmp[prev_idx])
        {
            prev_idx = lps[prev_idx - 1];
        }
        lps[i] = prev_idx + (kmp[i] == kmp[prev_idx] ? 1 : 0);
    }
    return lps[lps.size() - 1];
}

int32_t main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        
        string s;
        cin>>s;
        int n=s.length(), l=0, r=n-1;
        flp(i, 0, n)
        {
            if(l<r && s[l]==s[r])
            {
                l++;
                r--;
            }
        }
        
        if(l==s.length()/2)
        {
            cout<<s<<"\n";
            continue;
        }
        string s1="", s2="";
        s1=s.substr(0, l);
        s2=s.substr(l, s.length()-2*l);
        int len1=func(s2);
        reverse(s2.begin(), s2.end());
        int len2=func(s2);
        if(len1>=len2)
        {
            reverse(s2.begin(), s2.end());
            s1+=s2.substr(0, len1);
        }

        else s1+=s2.substr(0, len2);
        s1+=s.substr(r+1, l);
        cout<<s1<<"\n";     
    }
    return 0;
}