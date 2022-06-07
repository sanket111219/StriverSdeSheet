#include<bits/stdc++.h>
using namespace std;

void findCountByDfs(int i, int j, int ** arr, int n, int m, int* dx, int* dy)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
        return;
    
    arr[i][j] = 2;
    for(int k = 0; k < 8; k++)
    {
        int nexti = i + dx[k];
        int nextj = j + dy[k];
        if(nexti >=0 && nexti < n && nextj >= 0 && nextj < m && arr[nexti][nextj] == 1)
        {
            findCountByDfs(nexti, nextj, arr, n, m, dx, dy);
        }
    }
    
}


int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
    int countNoOfIsland = 0;
    
    int dx[] = {-1, -1, 0, +1, +1, +1, 0, -1};
    int dy[] = {0, +1, +1, +1, 0, -1, -1, -1};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 1)
            {
                countNoOfIsland++;
                findCountByDfs(i, j, arr, n, m, dx, dy);
            }   
        }
    }
    return countNoOfIsland;
}


int main()
{
    int n, m;
    cin >> n >> m;

    int ** arr = new int* [n];

    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = getTotalIslands(arr, n, m);
    cout << ans << endl;

}
