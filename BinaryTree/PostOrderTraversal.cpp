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

void postOrderTraversal(TreeNode* root, vector<int> &ans)
{
    if(root == NULL)
        return;
    
    postOrderTraversal(root->left, ans);
    postOrderTraversal(root->right, ans);
    ans.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    postOrderTraversal(root, ans);
    return ans;
}