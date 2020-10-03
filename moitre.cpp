#include <bits/stdc++.h>

#define ll long long int 
#define vi vector<int>
#define ii pair<int, int>

using namespace std;
bool visited[1000000];

int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		int x, y, e, citiesbought=0;
		cin>>e;
		
		memset(visited, 0, sizeof(visited));
		for(int i=0; i<e; i++)
		{
			cin>>x>>y;
			if( (!visited[x]) || (!visited[y]) )
			{
				if((!visited[x]) && (!visited[y]))
				{
					if(x!=y)
						citiesbought+=2;
					else
						citiesbought+=1;
					visited[x]=true;
					visited[y]=true;
				}

				else if(!visited[x])
				{
					visited[x]=true;
					citiesbought+=1;
				}

				else
				{
					visited[y]=true;
					citiesbought+=1;
				}
			}
		}

		cout<<citiesbought<<"\n";
	}
	return 0;
}