/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
		ListNode *tail = NULL;
		
		int jinwei = 0;
		
		while (l1 != NULL || l2 != NULL) {
			int curData = 0;
			
			if (l1 != NULL) {
				curData += l1->val;
				l1 = l1->next;
			}
			
			if (l2 != NULL) {
				curData += l2->val;
				l2 = l2->next;
			}
			
			int curValue;
			
			if (curData + jinwei >= 10) {
				curValue = curData + jinwei - 10;
				jinwei = 1;
			} else {
				curValue = curData + jinwei;
				jinwei = 0;
			}
			
			if (head == NULL) {
				head = new ListNode(curValue);
				tail = head;
			} else {
				ListNode *tmp = new ListNode(curValue);
				tail->next = tmp;
				tail = tail->next;
			}
			
		}
		
		if (jinwei != 0) {
			ListNode *tmp = new ListNode(jinwei);
			tail->next = tmp;
			tail = tail->next;
		}
		
		return head;
    }
};