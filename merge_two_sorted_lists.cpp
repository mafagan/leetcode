#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode *res = new ListNode(0);
        ListNode *reList = res;

        while(l1 || l2){
            if(!l1){
                res->next = new ListNode(l2->val);
                l2 = l2->next;
                res = res->next;
            }else if(!l2){
                res->next = new ListNode(l1->val);
                l1 = l1->next;
                res = res->next;
            }else{
                if(l1->val > l2->val){
                    res->next = new ListNode(l2->val);
                    l2 = l2->next;
                    res = res->next;
                }else{
                    res->next = new ListNode(l1->val);
                    l1 = l1->next;
                    res = res->next;
                }
            }
        }

        return reList->next;
    }
};
