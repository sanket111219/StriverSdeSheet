#include<bits/stdc++.h>
using namespace std;


class Queue {
private:
	int *arr;
	int qfront;
	int rear;
public:
    Queue() {
        // Implement the Constructor
		arr = new int[10001];
		qfront = 0;
		rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
		if(qfront == rear)
			return true;
		
		return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
		arr[rear] = data;
		rear++;
		
    }

    int dequeue() {
        // Implement the dequeue() function
		if(qfront == rear)
		{
			return -1;
		}
		int element = arr[qfront];
		qfront++;
		if(qfront == rear)
			qfront = rear = 0;
		
		return element;
    }

    int front() {
        // Implement the front() function
		if(qfront == rear)
			return -1;
		return arr[qfront];
    }
};