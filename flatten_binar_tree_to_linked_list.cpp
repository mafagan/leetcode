class Solution{
public:
    TreeNode *list;
    TreeNode *temp;

    TreeNode *preorder(TreeNode *root){
        if(root == NULL)
            return NULL;
        temp->val = root->val;
        
        if(root->left != NULL && root->right != NULL){
            temp->right = new TreeNode(0);
            temp->left = NULL;
            temp = temp->right;
        }

        preorder(root->left);
        preorder(root->right);

    }
    void flatten(TreeNode *root){
        if(root == NULL)
            return;

        list = new TreeNode(0);
        temp = list;
        preorder(root);
        root->right = list->right;
        root->left = NULL;
    }
};
