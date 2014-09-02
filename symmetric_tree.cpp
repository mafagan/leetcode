
// Definition for binary tree
#include <stdlib.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    bool isSym(TreeNode *p, TreeNode *q){
        if(p == NULL || q == NULL)
            return p == q;

        if(p->val != q->val)
            return false;

        return isSym(p->left, q->right) && isSym(p->right, q->left);

    }
    bool isSymmetric(TreeNode *root){
    	if (root == NULL)
    	{
    		/* code */
    		return true;
    	}
        return isSym(root->left, root->right);
    }
};
