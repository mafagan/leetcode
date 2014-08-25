#include <vector>
#include <limits.h>
class Solution{
public:
    int max_res = INT_MIN;
    int max(int a, int b){
        if(a > b)
            return a;
        else
            return b;
    }
    
    int maxCal(TreeNode *root){
        if(root == NULL)
            return 0;
        int left = maxCal(root->left);
        int right = maxCal(root->right);

        int temp_max = max(left, right);
        if(temp_max < 0)
            temp_max = 0;
        int max_value = temp_max + root->val;

        int temp_res = 0;
        if(left > 0)
            temp_res += left;

        if(right > 0)
            temp_res += right;

        temp_res += root->val;

        if(temp_res > max_res)
            max_res = temp_res;

        return max_value;
    }

    int maxPathSum(TreeNode *root){
        maxCal(root);
        return max_res;
    }
};
