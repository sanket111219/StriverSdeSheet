#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> ans(n);
    stack<int> s;
    
    s.push(INT_MAX);
    
    for(int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while(s.top() <= curr)
            s.pop();
        
        if(s.top() == INT_MAX)
            ans[i] = -1;
        else
            ans[i] = s.top();
        s.push(curr);
    }
    return ans;

}