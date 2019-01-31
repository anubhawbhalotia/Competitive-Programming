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
    void deleteNode(ListNode* node) {
        ListNode* p=node,  *prev=NULL;
        while(p!=NULL && p->next!=NULL)
        {
            p->val=p->next->val;
            prev=p;
            p=p->next;
        }
        prev->next=NULL;
        
    }
};