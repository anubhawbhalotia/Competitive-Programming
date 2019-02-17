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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *s = head, *prev = NULL, *e, *temp, *x, *q, *g;
        int c;
        while(1)
        {
            e = s;
            c = k-1;
            while(e!=NULL && c!=0)
            {
                e = e -> next;
                c--;
            }
            if(e==NULL)
                break;
            temp = s;
            x = NULL;
            g = e->next;
            while(s!=g)
            {
                q = s->next;
                if(x!=NULL)
                    s->next = x;
                x = s;
                s = q;
            }
            temp->next = s;
            if(prev==NULL)
                head = x;
            else
                prev->next = x;
            prev = temp;
        }
        return head;
    }
};