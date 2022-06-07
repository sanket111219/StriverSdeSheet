#include<bits/stdc++.h>
using namespace std;

void createIndegreeArray(vector<int> &indegree, vector<vector<int>> adj, int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(auto neighbour : adj[i])
        {
            indegree[neighbour]++;
        }
    }
    
}

void findCountForTopoSort(int &count, vector<int> &indegree, vector<vector<int>> adj, int n)
{
    queue<int>q;

    for(int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        count++;

        for(auto i : adj[front])
        {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        }
    }
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

    vector<int> indegree(n+1, 0);
    createIndegreeArray(indegree, adj, n);

    int count = 0;
    findCountForTopoSort(count, indegree, adj, n);
    if(count == n)
        return false;
    
    return true;
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