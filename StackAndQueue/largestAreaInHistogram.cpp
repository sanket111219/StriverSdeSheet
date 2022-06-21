#include<bits/stdc++.h>
using namespace std;


void getPrevSmaller(vector<int> &prevSmaller, int n, vector<int> &heights)
{
    stack<int> s;
    s.push(-1);
    for(int i = 0; i < n; i++)
    {
        int current = heights[i];
        while(s.top() != -1 && heights[s.top()] >= current)
        {
            s.pop();
        }

        prevSmaller[i] = s.top();
        s.push(i);
    }
}

void getNextSmaller(vector<int> &nextSmaller, int n, vector<int> &heights)
{
    stack<int> s;
    s.push(-1);
    for(int i = n-1; i>=0; i--)
    {
        int current = heights[i];
        while(s.top() != -1 && heights[s.top()] >= current)
        {
            s.pop();
        }
        
        nextSmaller[i] = s.top();
        s.push(i);
    }
}

int largestRectangle(vector < int > & heights) {
   // Write your code here.
     int n = heights.size();
     vector<int> nextSmaller(n);
     vector<int> prevSmaller(n);
     
     getNextSmaller(nextSmaller, n, heights);
     getPrevSmaller(prevSmaller, n, heights);
     
     int ans = INT_MIN;
     
     for(int i = 0; i < n; i++)
     {
         int length = heights[i];
         
         if(nextSmaller[i] == -1)
             nextSmaller[i] = n;
         
//          cout << nextSmaller[i] << " " << prevSmaller[i] << endl;
         int width = nextSmaller[i] - prevSmaller[i] - 1;
         
         int area = length * width;
         ans = max(ans, area);
     }
     
     return ans;
 }