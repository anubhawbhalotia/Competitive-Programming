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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        int a = 0, b = 0;
        while(p!=NULL)
        {
            p = p->next;
            a++;
        }
        while(q!=NULL)
        {
            q = q->next;
            b++;
        }
        p = headA;
        q = headB;
        int c = abs(a-b);
        if(a>b)
        {
            while(c)
            {
                p = p->next;
                c--;
            }
        }
        else if(a<b)
        {
            while(c)
            {
                q = q->next;
                c--;
            }
        }
        while(p!=NULL && q!=NULL)
        {
            if(p==q)
                return p;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};