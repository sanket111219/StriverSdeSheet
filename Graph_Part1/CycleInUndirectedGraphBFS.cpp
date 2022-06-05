#include <bits/stdc++.h>
using namespace std;

bool isCycleBFS(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited)
{
    queue<pair<int, int>> q;
    visited[node] = true;
    q.push({node, parent});

    while (!q.empty())
    {
        int frontNode = q.front().first;
        parent = q.front().second;
        q.pop();

        for (auto i : adj[frontNode])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push({i, frontNode});
            }
            else if (parent != i)
                return true;
        }
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
            if (isCycleBFS(i, -1, adj, visited))
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