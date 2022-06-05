#include <bits/stdc++.h>
using namespace std;

bool isCycle(int node, vector<vector<int>> &adj, vector<bool> &visited,
             vector<bool> &dfsVis)
{
    visited[node] = true;
    dfsVis[node] = true;
    for (auto &i : adj[node])
    {
        if (!visited[i])
        {
            if (isCycle(i, adj, visited, dfsVis))
                return true;
        }
        else if (dfsVis[i])
            return true;
    }
    dfsVis[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    vector<vector<int>> adj(n + 1);

    for (auto &i : edges)
    {
        int u = i.first;
        int v = i.second;

        adj[u].push_back(v);
    }

    vector<bool> visited(n + 1, false);
    vector<bool> dfsVis(n + 1, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            if (isCycle(i, adj, visited, dfsVis))
                return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {

        int n, m;
        cin >> n;
        cin >> m;

        vector<pair<int, int>> edges(m);

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            edges[i].first = a;
            edges[i].second = b;
        }

        bool ans = detectCycleInDirectedGraph(n, edges);

        string print = (ans) ? "true" : "false";
        cout << print << endl;
    }
}