#include<bits/stdc++.h>
using namespace std;
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    vector<int> ans;
    deque<int> maxi(k);
    
    for(int i = 0; i < k; i++)
    {
        while(!maxi.empty() && nums[maxi.back()] <= nums[i])
        {
            maxi.pop_back();
        }
        maxi.push_back(i);
    }
    
    ans.push_back(nums[maxi.front()]);
    
    for(int i = k; i < nums.size(); i++)
    {
        if(!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        
        while(!maxi.empty() && nums[maxi.back()] <= nums[i])
            maxi.pop_back();
        
        maxi.push_back(i);
        ans.push_back(nums[maxi.front()]);
    }
    return ans;
}