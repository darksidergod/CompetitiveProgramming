#include <bits/stdc++.h>

using namespace std;
#define SIZE 200001
bool myfunc(int it, string s1, string s2, int * a)
{
	// /cout<<it<<"\n";
	int n=s1.length();
	for(int i=0; i<it; i++)
		s1[a[i]-1]='*';
	//cout<<s1<<"\n";
	//cout<<s2<<"\n";
	int j=0;
	for(int i=0; i<n; i++)
	{
		if(s2[j]==s1[i]) j++;
		if(j==s2.length()) break;
	}
	//cout<<j<<"\n";
	if(j==s2.length())
		return true;

	else
		return false;
}
int main(void)
{
	string s1, s2;
	cin>>s1; cin>>s2;
	int n1 =s1.length(), n2=s2.length(); 
	int a[n1], dp[n1+1][26], req[26]; 
	bool check[n1]; for(int i=0; i<n1; i++) check[i]=true;
	memset(dp, 0, sizeof(dp));
	memset(req, 0, sizeof(req));
	for(int i=0; i<n2; i++) req[s2[i]-'a']++;
	
	for(int i=0; i<n1; i++) cin>>a[i];



	 int lo=0, hi=n1-1, mid;
	
	 while(lo<hi)
	 {
	 	mid=lo+(hi-lo)/2;
	 	//cout<<"mid is "<<mid<<"\n";
	 	if(myfunc(mid, s1, s2, a)) lo=mid;
	 	else hi=mid-1;

	 	if(hi-lo<=1) break;
	 }

	 if(myfunc(hi, s1, s2, a)) cout<<hi<<"\n";
	 else cout<<lo<<"\n";


	return 0;
}