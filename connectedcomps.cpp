#include <bits/stdc++.h>

using namespace std;
bool visited[10];
vector<int> adj[10];
void initialize()
{
	for(int i=0; i<10; i++)
		visited[i]=false;
}

void dfs(int r)
{
	stack<int> s;
	visited[r]=true;
	for(int i=0; i<adj[r].size(); i++)
	{
		if(!visited[adj[r][i]])
			s.push(adj[r][i]);
	}

	while(!s.empty())
	{
		int v = s.top();
		s.pop();
		for(int j=0; j<adj[v].size(); j++)
		{
			if(!visited[adj[v][j]])
				s.push(adj[v][j]);
		}
		visited[v]=true;
	}
}

void dfs2(int r)
{
	stack<int> s;
	s.push(r);
	while(!s.empty())
	{
		int v = s.top();
		s.pop();
		for(int j=0; j<adj[v].size(); j++)
		{
			if(!visited[adj[v][j]])
				s.push(adj[v][j]);
		}
		visited[v]=true;
		cout<<"visited "<<v<<"\n";
	}
}

int main() {
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

    for(int i = 1;i <= nodes;++i) 
    {
     if(visited[i] == false)     
      {
         dfs2(i);
         connectedComponents++;
      }
    }
    //cout<<visited[1]<<"\n";
    cout << "Number of connected components: " << connectedComponents << endl;
    return 0;
}