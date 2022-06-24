/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> ans;
    if(root == NULL)
        return ans;
    
    map<int, int> topNode;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        TreeNode<int>* node = temp.first;
        int hd = temp.second;
        
        if(topNode.find(hd) == topNode.end())
            topNode[hd] = node->val;
        
        if(node->left)
            q.push({node->left, hd-1});
        if(node->right)
            q.push({node->right, hd+1});
    }
    
    for(auto i : topNode)
    {
        ans.push_back(i.second);
    }
    
    return ans;
}