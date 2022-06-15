#include<bits/stdc++.h>
using namespace std;


bool isPossible(vector<int> &pos, int n, int c, int mid)
{
    int playerCount = 1;
    int lastRoom = pos[0];
    
    for(int i = 0; i < n; i++)
    {
        if(pos[i] - lastRoom >= mid)
        {
            playerCount++;
            if(playerCount == c)
                return true;
            
            lastRoom = pos[i];
        }
    }
    return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    
    sort(positions.begin(), positions.end());
    
    int start = 0;
    int maxi = INT_MIN;
    for(int i =0 ;i < n; i++)
    {
        maxi = max(maxi, positions[i]);
    }
    
    int end = maxi;
    
    int ans = -1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        
        if(isPossible(positions, n, c, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return ans;
}