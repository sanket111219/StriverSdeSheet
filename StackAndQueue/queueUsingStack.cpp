#include<stack>
using namespace std;
class Queue {
    // Define the data members(if any) here.
    stack<int> s1, s2;
    int size;
    
    public:
    Queue() {
        // Initialize your data structure here.
        size = 0;
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s1.push(val);
        size++;
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(size==0)
            return -1;
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int element = s2.top();
        s2.pop();
        size--;
        return element;
    }

    int peek() {
        // Implement the peek() function here.
        if(size==0)
            return -1;
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        if(size == 0)
            return 1;
        return 0;
    }
};