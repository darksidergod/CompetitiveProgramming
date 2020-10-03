#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string s1, s2;
	string s3="", s4="";
	cin>>s1>>s2;
	
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	reverse(s2.begin(), s2.end());
	int n = s1.length(), i=0, j=0, k=0;
	deque<char> a, b;
	
	for(int k=0; k<n; k++) a.push_back(s1[k]);
	for(int k=0; k<n; k++) b.push_back(s2[k]);

	bool flag=(s1[0]<s2[0]);

	for(int i=0; i<n; i++)
	{
		if(i%2==0)
		{
			if(!b.empty() && a[0]>=b[0]) flag=true;

			if(flag)
			{
				s4+=a.back();
				a.pop_back();
			}

			else
			{
				s3+=a.front();
				a.pop_front();
			}
		}

		else
		{
			if(!a.empty() && a[0]>=b[0]) flag=true;

			if(flag)
			{
				s4+=b.back();
				b.pop_back();
			}

			else
			{
				s3+=a.front();
				a.pop_front();
			}
		}
	}

	reverse(s4.begin(), s4.end());
	s3+=s4;
	cout<<s3<<"\n";
	return 0;
}