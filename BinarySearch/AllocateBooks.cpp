#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &time, int n, int m, long long mid)
{
    long long sum = 0;
    int count = 1;
    for(int i = 0; i < m; i++)
    {
        
        if(time[i] + sum <= mid)
            sum += time[i];
        else
        {
            count++;
            if(count > n || time[i] > mid)
                return false;
            sum = time[i];
        }
        
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    
    
    int mini = INT_MAX;
    long long sum = 0;
    for(int i = 0; i < m; i++)
    {
        sum += time[i];
        mini = min(mini, time[i]);
    }
    
    long long start = mini;
    long long end = sum;
    
    long long ans = -1;
    while(start <= end)
    {
        long long mid = start + (end - start)/2;
        
        if(isPossible(time, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}