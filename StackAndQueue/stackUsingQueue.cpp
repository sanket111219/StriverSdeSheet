#include<bits/stdc++.h>
using namespace std;
class Stack {
	// Define the data members.
    
    queue<int> q1, q2;
    int size;
    int topElement;

   public:
    Stack() {
        // Implement the Constructor.
        size = 0;
        topElement = -1;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(size == 0)
            return 1;
        return 0;
    }

    void push(int element) {
        // Implement the push() function.
        q1.push(element);
        topElement = element;
        size++;
    }

    int pop() {
        // Implement the pop() function.
        if(size == 0)
            return -1;
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int element = q1.front();
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            topElement = q2.front();
            q2.pop();
        }
        size--;
        if(size == 0)
            topElement = -1;
        return element;
            
        
    }

    int top() {
        // Implement the top() function.
        return topElement;
    }
};