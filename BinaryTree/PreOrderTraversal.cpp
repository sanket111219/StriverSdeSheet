#include<bits/stdc++.h>
using namespace std;
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void preOrderTraversal(TreeNode* root, vector<int> &ans)
{
    if(root == NULL)
        return;
    
    ans.push_back(root->data);
    preOrderTraversal(root->left, ans);
    preOrderTraversal(root->right, ans);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    preOrderTraversal(root, ans);
    return ans;
}