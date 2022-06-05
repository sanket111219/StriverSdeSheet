#include <bits/stdc++.h>
using namespace std;

void bfs(int node, int vertex, vector<set<int>> &adj, vector<bool> &visited,
         vector<int> &ans)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        ans.push_back(frontNode);
        q.pop();

        for (auto &i : adj[frontNode])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    int E = edges.size();
    vector<int> ans;
    vector<set<int>> adj(vertex);
    for (int i = 0; i < E; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<bool> visited(vertex, false);
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(i, vertex, adj, visited, ans);
        }
    }
    return ans;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> edges(E);
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;

        edges[i].first = a;
        edges[i].second = b;
    }

    vector<int> ans = BFS(V, edges);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}