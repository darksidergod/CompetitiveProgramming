#include <bits/stdc++.h>

using namespace std;
vector<int> adj[10];
bool visited[10];
int level[10];

void initialize()
{
	for(int i=0; i<10; i++)
		visited[i]=false;
}

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	visited[s]=true;
	level[s]=0;
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		for(int i=0; i<adj[s].size(); i++)
		{
			if(!visited[adj[s][i]])
				{
					q.push(adj[s][i]);
					level[adj[s][i]]=level[s]+1;
					visited[adj[s][i]]=true;
				}
		}
	}
}

int main(void)
{
	int nodes, edges, x, y, connectedComponents = 0;
    cin >> nodes;                       // Number of nodes
    cin >> edges;                       // Number of edges
    for(int i = 0;i < edges;++i) {
     cin >> x >> y;     
 // Undirected Graph 
     adj[x].push_back(y);                   // Edge from vertex x to vertex y
     adj[y].push_back(x);                   // Edge from vertex y to vertex x
    }

    initialize();                           // Initialize all nodes as not visited

    int startNode;
    cin>>startNode;
    bfs(startNode);        
    for(int i=0; i<nodes; i++)
    	cout<<level[i]<<"\n";

    return 0;
}