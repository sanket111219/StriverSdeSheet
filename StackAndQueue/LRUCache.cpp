#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    
    int size;
    class Node{
        public:
            int key;
            int value;
            Node* prev;
            Node* next;
        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
            prev = NULL;
            next = NULL;
        }
        
    };
    
    Node* head;
    Node* tail;
    
    unordered_map<int, Node*> cache;
    
    LRUCache(int capacity)
    {
        // Write your code here
        size = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newNode)
    {
        newNode->prev = head;
        newNode->next = head->next;
        head->next = newNode;
        newNode->next->prev = newNode;
    }
    
    void deleteNode(Node* deleteNode)
    {
        deleteNode->prev->next = deleteNode->next;
        deleteNode->next->prev = deleteNode->prev;
        deleteNode->prev = NULL;
        deleteNode->next = NULL;
//         delete deleteNode;
//         deleteNode = NULL;
    }
    int get(int key)
    {
        // Write your code here
        if(cache.find(key) != cache.end())
        {
            Node* resNode = cache[key];
            int result = resNode->value;
            cache.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            cache[key] = head->next;
            return result;
        }
        return -1;
        
    }

    void put(int key, int value)
    {
        // Write your code here
        if(cache.find(key) != cache.end())
        {
            Node* node = cache[key];
            cache.erase(key);
            deleteNode(node);
        }
        if(cache.size() == size)
        {
            cache.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        cache[key] = head->next;
        
    }
};
