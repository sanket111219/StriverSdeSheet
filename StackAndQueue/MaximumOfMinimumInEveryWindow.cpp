#include<bits/stdc++.h>
using namespace std;

// int findMaximumofMinimum(vector<int> &a, int n, int k)
// {
//     deque<int> dq;
//     int maxi = INT_MIN;
//     for(int i = 0; i < k; i++)
//     {
//         while(!dq.empty() && a[dq.back()] >= a[i])
//             dq.pop_back();
        
//         dq.push_back(i);
//     }
//     maxi = max(maxi, a[dq.front()]);
    
//     for(int i = k; i < n; i++)
//     {
//         if(!dq.empty() && i - dq.front() >= k)
//             dq.pop_front();
        
//         while(!dq.empty() && a[dq.back()] >= a[i])
//             dq.pop_back();
        
//         dq.push_back(i);
        
//         maxi = max(maxi, a[dq.front()]);
//     }
    
//     return maxi;
// }

void findPrevSmaller(vector<int> &a, vector<int> &prevSmaller, int n)
{
    stack<int> s;
    s.push(-1);
    
    for(int i = 0; i < n; i++)
    {
        int curr = a[i];
        while(s.top() != -1 && a[s.top()] >= curr)
            s.pop();
         
        prevSmaller[i] = s.top();
        s.push(i);
    }
}

void findNextSmaller(vector<int> &a, vector<int> &nextSmaller, int n)
{
    stack<int> s;
    s.push(-1);
    
    for(int i = n-1; i >= 0; i--)
    {
        int curr = a[i];
        while(s.top() != -1 && a[s.top()] >= curr)
            s.pop();
         
        nextSmaller[i] = s.top();
        s.push(i);
    }
}


vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int> ans(n, INT_MIN);
    vector<int> nextSmaller(n);
    vector<int> prevSmaller(n);
    
    findNextSmaller(a, nextSmaller, n);
    findPrevSmaller(a, prevSmaller, n);
    
    for(int i = 0; i < n; i++)
    {
        if(nextSmaller[i] == -1)
            nextSmaller[i] = n;
        
        int index = (nextSmaller[i] - prevSmaller[i] - 1) - 1;
        ans[index] = max(ans[index], a[i]);
    }
    
    for(int i = n-1; i > 0; i--)
    {
        ans[i-1] = max(ans[i-1], ans[i]);
    }
    return ans;
    
}