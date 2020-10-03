#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define F first
#define S second

int32_t main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k, ma;
        string s;
        cin>>n>>k;
        cin>>s;
        char c;
        int occurs[26]={0};
        char ans[k];
        flp(i, 0, k/2)
        {
            memset(occurs, 0, sizeof(occurs));
            ma=0;
            flp(j, 0, n/k)
            {
                c = s[k*j+i];
                occurs[c-'a']++;
                c = s[k*(j+1)-i-1];
                occurs[c-'a']++;
            }

            flp(j, 0, 26)
            {
                if(occurs[ma]<occurs[j])
                {
                    ma=j;
                }
            }
            ans[i]='a'+ma;
            ans[k-1-i]=ans[i];
        }

        if(k%2!=0)
        {
            memset(occurs, 0, sizeof(occurs));
            flp(j, 0, n/k)
            {
                c=s[k/2+k*j];
                occurs[c-'a']++;
            }
            ma=0;
            flp(j, 0, 26)
            {
                if(occurs[ma]<=occurs[j])
                {
                    ma=j;
                }
            }
            ans[k/2]='a'+ma;
        }
        string s2="";
        string s1="";
        flp(i, 0, k) s1+=ans[i];       
        flp(i, 0, n/k) s2+=s1;
        int ct=0;
        flp(i, 0, n)
        {
            if(s[i]!=s2[i]) ct++;
        }
      //  flp(i, 0, k)
      //   cout<<ans[i];
      //  cout<<"\n";
        cout<<ct<<"\n";
        
    }
    return 0;
}