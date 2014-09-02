/*
 * =====================================================================================
 *
 *       Filename:  path_sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday, September 02, 2014 09:15:44 HKT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
    public:

        bool cal(TreeNode *root, int sum, int calsum){
            if(root == NULL)
                return calsum == sum;
            calsum += root->val;
           
            if(root->left != NULL && root->right != NULL)
                return (cal(root->left, sum, calsum) || cal(root->right, sum, calsum));
            
            if(root->left != NULL)
                return cal(root->left, sum, calsum);

            if(root->right != NULL)
                return cal(root->right, sum, calsum);

            return calsum == sum;
        }
        bool hasPathSum(TreeNode *root, int sum) {
            if(root == NULL)
                return false;
            return cal(root, sum, 0);
        }

};
