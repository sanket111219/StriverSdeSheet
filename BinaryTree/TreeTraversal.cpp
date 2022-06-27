/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int> inOrder;
    vector<int> preOrder;
    vector<int> postOrder;
    vector<vector<int>> ans;
    stack<pair<BinaryTreeNode<int>*, int>> s;
    if(root == NULL)
        return ans;
    s.push({root, 1});
    
    while(!s.empty())
    {
        auto temp = s.top();
        s.pop();
        BinaryTreeNode<int>* frontNode = temp.first;
        int number = temp.second;
        if(number == 1)
        {
            preOrder.push_back(frontNode->data);
            number++;
            s.push({frontNode, number});
            if(frontNode->left)
                s.push({frontNode->left, 1});
        } 
        else if(number == 2)
        {
            inOrder.push_back(frontNode->data);
            number++;
            s.push({frontNode, number});
            if(frontNode->right)
                s.push({frontNode->right, 1});
        }
        else if(number == 3)
            postOrder.push_back(frontNode->data);
   
    }
    ans.push_back(inOrder);
    ans.push_back(preOrder);
    ans.push_back(postOrder);
}