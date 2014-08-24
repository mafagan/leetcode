/**
 *   Definition for binary tree
 *   struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *   };
 */
#include <iostream>
using namespace std;

class Solution {
    public:
        int abs(int data){
            if(data < 0)
                return -data;
            else
                return data;
        }

        int max(int data1, int data2)
        {
            if(data2 > data1)
                return data2;
            else
                return data1;
        }

        bool isBalanced(TreeNode *root) {
            if(root == NULL)
                return true;

            if(root->left == NULL && root->right == NULL)
            {
                root->value = 1;
                return true;
            }

            bool c_left = isBalanced(root->left);
            if(!c_left)
                return false;

            bool c_rightc = isBalanced(root->right);
            if(!c_rightc)
                return false;

            int l_height, r_height;

            if(root->left != NULL)
                l_height = root->left->value;
            else
                l_height = 0;

            if(root->right != NULL)
                r_height = root->right->value;
            else
                r_height = 0;

            if(abs(l_height - r_height) > 1)
                return false;

            root->value = max(l_height, r_height) + 1;
            return true;
        }
};

int main(int argc, char **argv)
{

    return 0;
}
