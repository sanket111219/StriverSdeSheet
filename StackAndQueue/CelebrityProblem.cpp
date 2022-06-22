#include<bits/stdc++.h>
using namespace std;

/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
    stack<int> s;
    for(int i = 0; i < n; i++)
    {
        s.push(i);
    }
    
    while(s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        
        if(knows(a, b))
            s.push(b);
        else
            s.push(a);
    }
    
    
    // in stack there may be a potential candidate
    for(int i = 0; i < n; i++)
    {
        if(i != s.top() && (knows(s.top(), i) || !knows(i, s.top()) ))
            return -1;
    }
    return s.top();
}