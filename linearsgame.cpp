#include <bits/stdc++.h>

using namespace std;
#define SIZE 200001

int main(void)
{
	string s1, s2;
	cin>>s1; cin>>s2;
	int n1 =s1.length(), n2=s2.length(); 
	int a[n1], dp[n1+1][26], req[26]; 
	bool check[n1]; for(int i=0; i<n1; i++) check[i]=true;
	check[0]=true;
	memset(dp, 0, sizeof(dp));
	memset(req, 0, sizeof(req));
	for(int i=0; i<n1; i++) dp[0][s1[i]-'a']++;

	for(int i=0; i<n2; i++) req[s2[i]-'a']++;
	
	for(int i=0; i<n1; i++) cin>>a[i];

	for(int i=0; i<n1; i++)
	{
		int it = s1[(a[i]-1)]-'a';
		for(int j=0; j<26; j++)
			{
				if (j==it) dp[i+1][j]=dp[i][j]-1;
				else dp[i+1][j]=dp[i][j];
			}
	}

	for(int i=0; i<n1; i++)
	{
		for(int j=0; j<26; j++)
		{
			if(dp[i+1][j]<req[j]) check[i]=false;
		}
	}

	for(int i=0; i<n; i++)
	{

	}
	



	return 0;
}