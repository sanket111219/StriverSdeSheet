#include<bits/stdc++.h>
using namespace std;

void doTopoSort(int node, vector<vector<int>> &adj, vector<bool> &visited, 
                stack<int> &s)
{
    visited[node] = true;
    for(auto &i : adj[node])
    {
        if(!visited[i])
            doTopoSort(i, adj, visited, s);
    }
    s.push(node);
}

void kosarajuDFS(int node, vector<vector<int>> &transAdj, stack<int> &s, 
              vector<bool> &visited, vector<int> &temp)
{
    visited[node] = true;
    temp.push_back(node);
    for(auto &i : transAdj[node])
    {
        if(!visited[i])
        {
            kosarajuDFS(i, transAdj, s, visited, temp);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> ans;
    int m = edges.size();


    // adj list for do dfs in forward direction
    vector<vector<int>> adj(n);

    // transpose adj list for do dfs in backward direction
    vector<vector<int>> transAdj(n);
    for(int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        transAdj[v].push_back(u);
    }
    
    vector<bool> visited(n, false);
    stack<int> s;

    // step 1 : we have to do toposort inorder to get their order of finishing time
    // that means to get the first node at first and next node in next, and we have to store it in stack
    // because of get the sequence in correct order.
    for(int i = 0; i < n; i++)
    {
         if(!visited[i])
         {
             doTopoSort(i, adj, visited, s);
         }
    }
    
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    

    //step 2: In this stage we have to make the transpose adj list. With the help of the transpose adjlist
    //when we do dfs inorder of finishing time it will not access the not strongly connected componets


    // step 3: In this stage we have to do dfs according to the element of stack
    // here it will print only the strongly connected components.
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        if(!visited[node])
        {
            vector<int> temp;
            kosarajuDFS(node, transAdj, s, visited, temp);
            ans.push_back(temp);
        }
    }
    
    
    return ans;
}