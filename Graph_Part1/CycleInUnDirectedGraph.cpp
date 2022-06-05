#include <bits/stdc++.h>
using namespace std;

bool isCycle(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            if (isCycle(i, node, adj, visited))
                return true;
        }
        else if (parent != i)
            return true;
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCycle(i, -1, adj, visited))
            {
                return "Yes";
            }
        }
    }
    return "No";
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[i][0] = a;
        edges[i][1] = b;
    }

    string ans = cycleDetection(edges, n, m);
    cout << ans << endl;
}
