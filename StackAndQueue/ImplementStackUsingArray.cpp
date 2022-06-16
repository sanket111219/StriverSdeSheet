// Stack class.
#include<bits/stdc++.h>
using namespace std;

class Stack {
    
public:
    int *arr;
    int topPointer;
    int size;
    
    Stack(int capacity) {
        // Write your code here.
        arr = new int[capacity];
        topPointer = -1;
        size = capacity;
    }

    void push(int num) {
        // Write your code here.
        topPointer++;
        if(topPointer == size)
            return;
        
        arr[topPointer] = num;
    }

    int pop() {
        // Write your code here.
        if(topPointer == -1)
            return -1;
        int element = arr[topPointer];
        topPointer--;
        return element;
    }
    
    int top() {
        // Write your code here.
        if(topPointer == -1)
            return -1;
        return arr[topPointer];
    }
    
    int isEmpty() {
        // Write your code here.
        if(topPointer == -1)
            return 1;
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(topPointer == size)
            return 1;
        return 0;
    }
    
};