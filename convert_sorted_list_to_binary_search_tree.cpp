class Solution{
public:
    int getLength(ListNode *head){
        int count = 0;

        while(head){
            ++ count;
            head = head->next;
        }

        return count;
    }
    
    ListNode *getMiddle(ListNode *head, int length){
        int middle = (length - 1) / 2;
        int count = 0;

        while(count < middle){
            head = head->next;
            ++ count;
        }

        return head;
    }

    TreeNode *convert(ListNode *head, int length){
        if(length == 0)
            return NULL;
        
        ListNode *mid = getMiddle(head, length);
        TreeNode *root = new TreeNode();
        root->val = mid->val;
        root->left = convert(head, (length-1)/2);
        root->right = convert(mid->next, length/2);

        return root;
    }

    TreeNode *sortedListToBST(ListNode *head){
        if(head == NULL)
            return NULL;
        int length = getLength(head)
        return convert(head, length);
        
    }
};
