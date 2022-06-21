#include<bits/stdc++.h>
using namespace std;
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};
    int total = 0, count = 0, minitues = 0;
    
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
           if(grid[i][j] != 0)
               total++;
            if(grid[i][j] ==2)
                q.push({i, j});
        }
    }
    
    while(!q.empty())
    {
        int component = q.size();
        count += component;
        while(component--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int nexti = x + di[i];
                int nextj = y + dj[i];
                
                if(nexti >= 0 && nextj >=0 && nexti < n && nextj < m && grid[nexti][nextj] == 1)
                {
                    grid[nexti][nextj] = 2;
                    q.push({nexti, nextj});
                }
            }
            
        }
        if(!q.empty())
            minitues++;
    }
    if(total == count)
        return minitues;
    return -1;
}