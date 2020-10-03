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
int dist[SIZE][SIZE];
int len=0;
pair<int, int> diamEnd;  

bool check(int x, int y)
{
    if(x<0 || y<0 || x>=n || y>=m)
        return false;

    else
        return true;
}

void bfs(int x, int y)
{
	vis[x][y]=true;
	queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty())
    {
        pair<int, int> u=q.front(), next;
        q.pop();
        flp(k, 0, 4)
        {
            int x=u.F+dx[k];
            int y=u.S+dy[k];
            if(check(x, y))
            {
                if(grid[x][y]=='.' && !vis[x][y])
                {
                    q.push({x,y});
                    dist[x][y]=1+dist[u.F][u.S];
                    vis[x][y]=true;

                    if(len<dist[x][y])
                    {
                        len=dist[x][y];
                        diamEnd={x,y};
                    }
                }
            }
        }
    }
   
}

int32_t main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
        scanf("%lld%lld", &m, &n);
        pair<int, int> start;
		len=0;
        int present=0;
        memset(vis, 0, sizeof(vis));
        flp(i, 0, n)
         scanf("%s", grid[i]);

        flp(i, 0, n)
        {
            flp(j, 0, n)
            {
                if(grid[i][j]=='.')
                {
                    start={i, j};
                    dist[i][j]=0;
                    present=1;
                    break;
                }
            }
            if(present)
             break;
        }

        bfs(start.F, start.S);
        memset(vis, 0, sizeof(vis));
        dist[diamEnd.F][diamEnd.S]=0;
        len=0;
        bfs(diamEnd.F, diamEnd.S);
        printf("Maximum rope length is %lld.\n",len);
	}
	return 0;
}

