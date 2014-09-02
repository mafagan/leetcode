/*
 * =====================================================================================
 *
 *       Filename:  sum_root_to_leaf.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday, September 02, 2014 10:13:59 HKT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winterma 
 *   Organization:  Intel
 *
 * =====================================================================================
 */
#include <stdlib.h>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
    int sum;

    public:
        void getSum(TreeNode *root, int cursum){
            if(root == NULL)
                return;

            cursum = cursum * 10 + root->val;
            if(root->left == NULL && root->right == NULL)
            {
                sum += cursum;
                return;
            }

            getSum(root->left, cursum);
            getSum(root->right, cursum);
        }

        int sumNumbers(TreeNode *root){
            sum = 0;
            getSum(root, 0);
            return sum;
        }
};
