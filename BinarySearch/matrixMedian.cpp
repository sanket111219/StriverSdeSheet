#include<bits/stdc++.h>
using namespace std;

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int mini = INT_MAX;
    int maxi = INT_MIN;
    
    for(int i = 0; i < n; i++)
    {
        mini = min(mini, matrix[i][0]);
        maxi = max(maxi, matrix[i][m-1]);
    }
    
    int start = mini;
    int end = maxi;
    
    int medianIndex = (m*n+1)/2;
    int ans;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        
        }
        
        if(count < medianIndex)
            start = mid + 1;
        
        else 
        {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}