#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define F first
#define S second
#define SIZE 4000

vector<char> v;
int dp[SIZE][SIZE];
string a, b;

int32_t main(void)
{
  cin>>a>>b;
//  memset(dp, -1, sizeof(dp));
  int n=a.length();
  int m=b.length();
 // myfunc(n, m);
  int key=1;
  string s="";
  
  flp(i, 0, n+1)
  {
  	flp(j, 0, m+1)
  	{
  		if(i==0 || j==0)
  		 dp[i][j]=0;

  		else if(a[i-1]==b[j-1])
  		 dp[i][j]=1+dp[i-1][j-1];	
  		
  		else
  		 dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
  		
  	//	cout<<dp[i][j]<<" ";
  	}
  //	cout<<"\n";
  }
 
  int i=n, j=m;
  while(i>0 && j>0)
  {
  	if(a[i-1]==b[j-1])
  	{
  		s+=a[i-1];
  		i--; j--;
  	}

  	else
  	{
  		if(dp[i][j]==dp[i-1][j])
  			i--;

  		else
  			j--;
  	}
  }
  reverse(s.begin(), s.end());
  cout<<s<<"\n";

  return 0;
}