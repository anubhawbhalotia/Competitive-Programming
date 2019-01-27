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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        struct ListNode *a=l1, *b=l2, *prev,*p,*head;
        int c=0;
        if(l1==NULL && l2==NULL)
        {
            return l1;
        }
        while(a!=NULL && b!=NULL)
        {
            if(a->val<b->val)
            {
                p=new ListNode(a->val);
                a=a->next;
            }
            else
            {
                p=new ListNode(b->val);
                b=b->next;
            }
            if(c!=0)
            {
                prev->next=p;
            }
            else
            {
                head=p;
            }
            p->next=NULL;
            prev=p;
            c++;
        }
        while(a!=NULL)
        {
            p=new ListNode(a->val);
            if(c!=0)
                prev->next=p;
            else
                head = p;
            a=a->next;
            prev=p;
            c++;
        }
        while(b!=NULL)
        {
            p=new ListNode(b->val);
            if(c!=0)
                prev->next=p;
            else
                head=p;
            b=b->next;
            prev=p;
            c++;
        }
        return head;
    }
    
};