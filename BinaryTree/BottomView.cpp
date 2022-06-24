/*************************************************************
 
    Following is the Binary Tree node structure.

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

*************************************************************/
vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int> ans;
    if(root == NULL)
        return ans;
    
    map<int, int> bottomNode;
    queue<pair<BinaryTreeNode<int>* , int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        pair<BinaryTreeNode<int>*, int> temp = q.front();
        q.pop();
        BinaryTreeNode<int>* Node = temp.first;
        int hd = temp.second;
        bottomNode[hd] = Node->data;
        if(Node->left)
            q.push({Node->left, hd-1});
        if(Node->right)
            q.push({Node->right, hd+1});
    }
    
    for(auto i: bottomNode)
    {
        ans.push_back(i.second);
    }
    return ans;
    
}
