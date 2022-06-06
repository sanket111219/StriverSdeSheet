#include<bits/stdc++.h>
using namespace std;



void topoSortBFS(vector<int> &indegree, vector<vector<int>> &adj,
                vector<int> &ans)
{
    queue<int> q;
    for(int i = 0; i < indegree.size(); i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i : adj[frontNode])
        {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        }
    }
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
    
   vector<int> indegree(V, 0);
    for(int i = 0; i < V; i++)
    {
        for(auto neighbour : adj[i])
        {
            indegree[neighbour]++;
        }
    }
    
    vector<int> ans;
    topoSortBFS(indegree, adj, ans);
    
    
    // for DFS it this part
//     while(!s.empty())
//     {
//         ans.push_back(s.top());
//         s.pop();
//     }
    
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