#include <bits/stdc++.h>
using namespace std;


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    
    vector<vector<pair<int, int>>> adj(vertices);
    for(int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    
    vector<int> dist(vertices, INT_MAX);
    
    // first = dist
    // second = node
    set<pair<int, int>> st;
    
    dist[source] = 0;
    st.insert({0, source});
    
    while(!st.empty())
    {
        pair<int, int> top = *(st.begin());
        int nodeDist = top.first;
        int node = top.second;
        st.erase(top);
        
        for(auto &neighbour : adj[node])
        {
            // first = dist, second = node
            if(neighbour.first + nodeDist < dist[neighbour.second])
            {
                auto existingPair = st.find({dist[neighbour.second], neighbour.second});
                if(existingPair != st.end())
                {
                    st.erase(existingPair);
                }
                
                dist[neighbour.second] = neighbour.first + nodeDist;
                st.insert({dist[neighbour.second], neighbour.second});
            }
        }
    }
    return dist;
}
