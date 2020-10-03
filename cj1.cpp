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
    flp(x, 0, t)
    {
      int n;
      cin>>n;
      vector<pair<pair<int, int>, int>> v;     
      flp(i, 0, n)
      {
          int x, y;
          cin>>x>>y;
          v.pb({{x, y}, i});          
      }
      char ans[n];
      bool flag=true;
      int f1=-1, f2=-1;
      sort(v.begin(), v.end()); 
      flp(i, 0, n)
      {
          if(v[i].F.F>=f1)
          {
              ans[v[i].S]='C';
              f1=v[i].F.S;
          }

          else if(v[i].F.F>=f2)
          {
              ans[v[i].S]='J';
              f2=v[i].F.S;
          }

          else
          {
              flag=false;
              break;
          }
      }
      cout<<"Case #"<<x+1<<": ";
      if(!flag) cout<<"IMPOSSIBLE\n";

      else{
          flp(i, 0, n)
           cout<<ans[i];
          cout<<"\n";
      }
      
    }
    return 0;
}