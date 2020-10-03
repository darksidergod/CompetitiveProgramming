#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main(void)
{
	ll q;
	cin >> q;
	while(q--)
	{
		string s;
		cin>>s;
		if(s.length()%2==0)
		{
			string s1="", s2="", p="";
			for(int i=0; i<s.length()/2; i++)
				s1+=s[i];
			for(int i=s.length()/2; i<s.length(); i++)
				s2+=s[i];

			if(s1>=s2)
			{
				int n=s1.length();
				for(int i=0; i<n; i++) p+=s1[i];
					
				for(int i=n-1; i>=0; i--) p+=s1[i];
			}

		}
	}

}