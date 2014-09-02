/*
 * =====================================================================================
 *
 *       Filename:  maximum_depth_of_binary_tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday, September 02, 2014 12:58:48 HKT
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
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    int bigger(int a, int b){
        if(a > b)
            return a;
        else
            return b;
    }
    int maxDepth(TreeNode *root){
        if(root == NULL)
            return 0;

        return (bigger(maxDepth(root->left), maxDepth(root->right)) + 1);
    }
};
