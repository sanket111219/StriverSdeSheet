/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bist/stdc++.h>
using namespace std;

pair<int, int> findDiameter(TreeNode<int>* root)
{
    if(root == NULL)
        return {0, 0};
    
    auto left = findDiameter(root->left);
    auto right = findDiameter(root->right);
    
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + 1 + right.second;
    
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    
    return ans;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    pair<int, int> ans = findDiameter(root);
    return ans.first-1;
}
