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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;
        ListNode *p=head, *q=head;
        do
        {
            p=p->next;
            q=q->next;
            if(q==NULL)
                return false;
            q=q->next;
        }while(p!=NULL && q!=NULL && p!=q);
        if(p==NULL || q==NULL)
            return false;
        return true;
    }
};
    