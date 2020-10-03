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

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int32_t main(void)
{
    int n, k, c;
    string s;
    cin>>n>>k>>c;
    cin>>s;
    vector<int> v1(k, 0), v2(k, 0);
    int j=0;
    flp(i, 0, k)
    {
        while(s[j]=='x') j++;
        v1[i]=j;
        j+=(c+1);
    }
    j=n-1;
    rev(i, k-1)
    {
        while(s[j]=='x') j--;
        v2[i]=j;
        j-=(c+1);
    }

    flp(i, 0, k)
    {
        if(v1[i]==v2[i]) cout<<v1[i]+1<<"\n";
    }


    return 0;

}