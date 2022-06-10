#include<bits/stdc++.h>


vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<vector<pair<int, int>>> adj(n+1);
    
    for(int i = 0; i < m; i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<int> value(n+1, INT_MAX), parent(n+1, -1);
    vector<bool> mstSet(n+1, false);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    value[1] = 0;
    pq.push({0, 1});
    for(int i = 0; i < n-1; i++)
    {
        int node = pq.top().second;
        pq.pop();
        mstSet[node] = true;
        for(auto &i : adj[node])
        {
            int neighbour = i.first;
            int weight = i.second;
            if(mstSet[neighbour] == false && weight < value[neighbour])
            {
                value[neighbour] = weight;
                parent[neighbour] = node;
                pq.push({value[neighbour], neighbour});
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> ans;
    for(int i = 2; i <= n; i++)
    {
        pair<int,int> ans1 = {parent[i], i};
        pair<pair<int, int>, int> ans2 = {ans1, value[i]};
        ans.push_back(ans2);
    }
    
    return ans;
    
}
