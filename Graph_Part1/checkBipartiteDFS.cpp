#include<bits/stdc++.h>
using namespace std;

bool checkBipartiteDFS(int node, vector<int> &color, vector<vector<int>> &adj)
{
    for(auto i: adj[node])
    {
        if(color[i] == -1)
        {
            color[i] = (color[node] == 1) ? 0 : 1;
            if(!checkBipartiteDFS(i, color, adj))
                return false;
        }
        else if(color[node] == color[i])
            return false;
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    int n = edges.size();
    int m = edges[0].size();
    
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    vector<int> color(n, -1);
    for(int i = 0; i < n; i++)
    {
        if(color[i] == -1)
        {
            color[i] = 1;
            if(!checkBipartiteDFS(i, color, adj))
                return false;
        }
            
    }
    return true;
    
}