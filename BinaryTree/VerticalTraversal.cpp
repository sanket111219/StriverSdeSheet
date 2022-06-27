/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;
    if(root == NULL)
        return ans;
    
    map<int, map<int, vector<int>>> nodes;
    queue<pair<TreeNode<int>*, pair<int, int>>> q;
    q.push({root, {0,0}});
    
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        TreeNode<int>* frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;
        
        nodes[hd][level].push_back(frontNode->data);
        
        if(frontNode->left)
            q.push({frontNode->left, {hd-1, level+1}});
        if(frontNode->right)
            q.push({frontNode->right, {hd+1, level+1}});
    }
    
    for(auto i : nodes)
        for(auto j : i.second)
            for(auto k : j.second)
                ans.push_back(k);
    
    return ans;
    
}