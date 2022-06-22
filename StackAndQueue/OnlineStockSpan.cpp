#include<bits/stdc++.h>
using namespace std;
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    int n = price.size();
    vector<int> ans(n);
    
    stack<int> s;
    s.push(-1);
    
    for(int i = 0; i < n; i++)
    {
        int current = price[i];
        while(s.top() != -1 && price[s.top()] <= current)
        {
            s.pop();
        }
        ans[i] = i - s.top();
        s.push(i);
    }
    return ans;
}