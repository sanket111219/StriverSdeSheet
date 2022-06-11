#include<bits/stdc++.h>
using namespace std;

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>> dist(n+1, vector<int>(n+1, 1e9));
    for(int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        
        dist[u][v] = wt;
    }
   

    for(int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    
//      for(int i = 0; i <= n; i++)
//      {
//          for(int j = 0; j <= n; j++){
//              cout << dist[i][j] << "   ";
//          }
//          cout << endl;
//      }

    
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                if(dist[i][k] == 1e9 || dist[k][j] == 1e9)
                    continue;
                
                else if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
    
    for(int i = 1; i <= n; i++)
    {
        if(dist[i][i] < 0)
            return -1;
    }
    
    return dist[src][dest];
                
    
}