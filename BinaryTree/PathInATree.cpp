/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

bool findNode(TreeNode<int>* root, int x, vector<int> &ans)
{
    if(root == NULL)
        return false;
    
    if(root->data == x)
    {
        ans.push_back(root->data);
        return true;
    }
        
    
    ans.push_back(root->data);
    bool left = findNode(root->left, x, ans);
    bool right = findNode(root->right, x, ans);
    
    if(left || right)
        return true;
    else
    {
        ans.pop_back();
        return false;
    }
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> ans;
    if(findNode(root, x, ans))
        return ans;
    
    
}
