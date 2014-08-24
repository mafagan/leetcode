#include <vector>

class Solution{
    public:
        vector<int> array;
        vector<int> inorderTraversal(TreeNode *root){
            if(root == NULL)
                return array;

            inorderTraversal(root->left);
            array.push_back(root->val);
            inorderTraversal(root->right);
            return array;
        }
};
