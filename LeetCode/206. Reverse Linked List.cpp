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
    ListNode* reverseList(ListNode* head) {
        struct ListNode *p,*newP,*prev=NULL;
        p=head;
        while(p!=NULL)
        {
            newP=new struct ListNode(p->val);
            newP->next = prev;
            prev=newP;
            p=p->next;
        }
        return prev;
    }
};