/**
 *  Definition for binary tree
 *  struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *  };
 *         */
#include <climits>
class Solution {
public:
    int previous = INI_MIN;
    
    bool isval(TreeNode* root, int& prev){
        if(root == NULL)
            return true;
        bool temp = true;

        temp = temp && isval(root->left, prev);
        
        if(prev >= root->val)
            temp = false;

        prev = root->val;

        temp = temp && isval(root->right, prev);
        return temp;
    }

    bool isValidBST(TreeNode *root) {     
        return isVal(root, prev);
    }

};
 
