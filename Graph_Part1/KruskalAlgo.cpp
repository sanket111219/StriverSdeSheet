#include<bits/stdc++.h>
using namespace std;


class node{
  public:
    int u;
    int v;
    int wt;
    
    node(int first, int second, int third)
    {
        u = first;
        v = second;
        wt = third;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findParent(int node, vector<int> &parent)
{
    if(parent[node] == node)
        return node;
    
    return parent[node] = findParent(parent[node], parent);
}

void unionOfComponent(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int parU = findParent(u, parent);
    int parV = findParent(v,parent);
    
    if(rank[parU] < rank[parV])
    {
        parent[parU] = parV;
    }
    else if(rank[parV] < rank[parU])
    {
        parent[parV] = parU;
    }
    else
    {
        parent[parV] = parU;
        rank[parU]++;
    }
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
    
    vector<node> edges;
    for(int i =0 ;i < m; i++)
    {
        edges.push_back(node(graph[i][0], graph[i][1], graph[i][2]));
    }
    
    sort(edges.begin(), edges.end(), comp);
    
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    for(int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
    
    int weight = 0;
    for(auto &it : edges)
    {
        if(findParent(it.u, parent) != findParent(it.v, parent))
        {
            weight += it.wt;
            unionOfComponent(it.u, it.v, parent, rank);
        }
    }
    return weight;
    
}