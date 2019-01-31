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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* p=head, *prev=NULL, *r=head->next, *temp;
        while(p!=NULL && p->next!=NULL)
        {
            if(prev!=NULL)
                prev->next=p->next;
            temp=p->next->next;
            p->next->next=p;
            p->next=temp;
            if(prev!=NULL)
                prev=prev->next->next;
            else
                prev=p;
            p=p->next;
        }
        return r;
    }
};