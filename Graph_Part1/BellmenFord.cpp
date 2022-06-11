#include<bits/stdc++.h>
using namespace std;


int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    
//     vector<node> adj;
//     for(int i = 0; i < m; i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         int w = edges[i][2];
        
//         adj.push_back(node(u, v, w));
//     }
    
    vector<int> dist(n+1, 1e9);
    
    dist[src] = 0;
    
    for(int i = 1; i <= n-1; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if(dist[u] != 1e9 && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    bool flag = 0;
    for(int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        if(dist[u] != 1e9 && dist[u] + w < dist[v])
        {
            flag = 1;
            break;
        }
    }
    if(!flag)
        return dist[dest];
    else
        return 1e9;
    
    
}