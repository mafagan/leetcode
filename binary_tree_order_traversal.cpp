#include <vector>
#include <queue>
class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode *root){
        vector<vector<int>> res;
        res.clear();

        if(root == NULL)
            return res;
        queue<TreeNode*> level_node;
            
        level_node.push(root);
        while(!level_node.empty()){
            vector<int> temp;
            queue<TreeNode*> temp_queue;

            while(!level_node.empty()){
                TreeNode *node_ptr = level_node.front();
                level_node.pop();
                temp_queue.push(node_ptr);
                temp.push_back(node_ptr->val);
            }
            res.push_back(temp);
            while(!temp_queue.empty()){
                TreeNode *tempNode = temp_queue.front();
                temp_queue.pop();
                if(tempNode->left != NULL)
                    level_node.push(tempNode->left);

                if(tempNode->right != NULL)
                    level_node.push(tempNode->right);
            }
        }

        return res;
    }
};
