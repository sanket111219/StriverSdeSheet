#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int V, vector<vector<int>> &adj, 
         vector<int> &ans, vector<bool> &visited)
{
    visited[node] = true;
    ans.push_back(node);
    for(auto it : adj[node])
    {
        if(!visited[it])
            dfs(it, V, adj, ans, visited);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> adj(V);
    for(int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int> >ans;
    vector<bool> visited(V, false);
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            vector<int>temp;
            dfs(i, V, adj, temp, visited);
            ans.push_back(temp);  
        }

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

    vector<vector<int>> ans = depthFirstSearch(V, E, edges);

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}