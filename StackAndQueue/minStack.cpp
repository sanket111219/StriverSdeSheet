// Implement class for minStack.
#include<bits/stdc++.h>
using namespace std;

class minStack
{
	// Write your code here.
	
	public:
		
        stack<int> s;
        int mini;
		// Constructor
		minStack() 
		{ 
			// Write your code here.
            
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            if(s.empty())
            {
                s.push(num);
                mini = num;
                
            }
            else
            {
               if(num < mini)
               {
                   int val = 2*num - mini;
                   s.push(val);
                   mini = num;
               }
                else
                {
                   s.push(num); 
                }
                   
            }
            
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
            if(!s.empty())
            {
                int curr = s.top();
                s.pop();
                if(curr > mini)
                    return curr;
                else
                {
                    int currentMin = mini;
                    mini = 2*mini - curr;
                    return currentMin;
                }
            }
            return -1;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if(!s.empty())
            {
                int curr = s.top();
                if(curr > mini)
                    return curr;
                else
                    return mini;
            }
            return -1;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(!s.empty())
                return mini;
            return -1;
		}
};