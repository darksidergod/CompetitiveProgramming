#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define F first
#define S second
#define SIZE 1005

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n, m;
char grid[SIZE][SIZE];
bool vis[SIZE][SIZE];
int ans=0;

void dfs(int x, int y, int nodeCount)
{
	if(x<0 || y<0 || x>=n || y>=m) return;
	vis[x][y]=true;
	nodeCount++;
	ans=max(ans, nodeCount);
	flp(k, 0, 4)
	{
		int xx=x+dx[k], yy=y+dy[k];
		if(!vis[xx][yy]) dfs(xx, yy, nodeCount);
		 
	}

	return ;
}

int32_t main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
//		int m, n;
		memset(vis, 0, sizeof(vis));
		scanf("%lld%lld", &m, &n);
		flp(i, 0, n) cin>>grid[i];
		int id=0;
		vector<pair<int, int>> v;
		
		flp(i, 0, n) flp(j, 0, m){
			if(grid[i][j]=='.')
			{
				int dots=0;
				flp(k, 0, 4)
				{
					int x=i+dx[k];
					int y=j+dy[k];
					if(x<0 || y<0 || x>=n ||y>=m ) continue;
					if(grid[x][y]=='.')
						dots++;
				}

				if(dots==1)
					v.pb({i, j});
			}
		}

		for(auto i:v)
			cout<<i.F<<" "<<i.S<<"\n";
		

		

		//cout<<"Maximum rope length is "<<(ans)<<".\n";
	}
	return 0;
}

