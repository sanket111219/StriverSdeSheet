#include<stack>
#include<vector>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>s;
    vector<int> ans(n);
    s.push(-1);
    
    for(int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while(s.top() >= curr)
            s.pop();
        
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
    
}