#include <vector>

classes Solution{
public:
    TreeNode *insertArray(vector<int> &num, int begin, int end){
        if(begin > end)
            return NULL;
        int middle = (begin + end)/2;

        TreeNode *root = new TreeNode(num[middle]);
        root->left = insertArray(num, begin, middle-1);
        root->right = insertArray(num, middle+1, end);

        return root;
    }

    TreeNode *sortArrayToBST(vector<int> &num){
        return insertArray(num, 0, num.size()-1);
    }
}
