#include<bits/stdc++.h>
using namespace std;
void topoSortDFS(int node, vector<bool>&visited, vector<vector<int>> &adj,
                stack<int> &s)
{
    visited[node] = true;
    for(auto &i : adj[node])
    {
        if(!visited[i])
        {
            topoSortDFS(i, visited, adj, s);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e)  {
    // Write your code here
    //adj list
    
    vector<vector<int>> adj(V);
    for(int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    vector<bool> visited(V, false);
    stack<int> s;
    vector<int> ans;
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
            topoSortDFS(i, visited, adj, s);
    }
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    
    for(int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[i][0] = a;
        edges[i][1] = b;
    }

    vector<int> ans = topologicalSort(edges, V, E);

    for(auto i: ans)
    {
        cout << i << " ";
    }cout << endl;
}