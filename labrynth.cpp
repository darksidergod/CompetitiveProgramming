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
int r, c;

char grid[SIZE][SIZE];

int root[SIZE][SIZE];
int sz[SIZE*SIZE];

void dfs(int rx, int ry, int ct)
{
	if(rx<0 || ry<0 || rx>=r || ry>=c) return;
	if(grid[rx][ry]=='*' || root[rx][ry]) return;

	root[rx][ry]=ct;
	sz[ct]++;
	flp(i, 0, 4)
		dfs(rx+dx[i], ry+dy[i], ct);
}


int32_t main(void)
{
	int t=1;
	//cin>>t;
	while(t--)
	{
		memset(root, 0, sizeof(root));
		memset(sz, 0, sizeof(sz));
		scanf("%lld%lld", &r,&c);
		flp(i, 0, r) cin>>grid[i];
		
		int ct=0;
		flp(i, 0, r)
		{
			flp(j, 0, c)
			{
				if(!root[i][j] && grid[i][j]=='.')
				{	
					ct++;
					dfs(i, j, ct);
				}
			}
		}

		flp(i, 0, r)
		{
			flp(j, 0, c)
			{
				if(grid[i][j]=='.') cout<<".";

				else
				{
					int ans=1;
					int root1=-1, root2=-1, root3=-1;
					flp(k, 0, 4)
					{
						int x=i+dx[k], y=j+dy[k];
						if(x<0 || y<0 || x>=r || y>=c) continue;
						if(root[x][y]==root1 || root[x][y]==root2 || root[x][y]==root3) continue;
						ans+=sz[root[x][y]];	
						if(root1==-1) root1=root[x][y];
						else if(root2==-1) root2=root[x][y];
						else if(root3==-1) root3=root[x][y];
					}
					cout<<(ans%10LL);
				}
				
			}
			cout<<"\n";
		}	
	}

	return 0;
}