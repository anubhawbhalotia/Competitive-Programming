/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* p=head, *newHead, *newP, *prev, *a[100000];
        set <pair< RandomListNode*, long>> s;
        long c=0;
        prev = NULL;
        while(p!=NULL)   
        {
            newP = new struct RandomListNode(p->label);
            if(c==0)
            {
                newHead = newP;
            }
            else
            {
                prev->next = newP;
            }
            prev=newP;
            newP->next=NULL;
            a[c] = newP;
            s.insert(make_pair(p, c));
            c++;
            p = p->next;
        } 
        p=head;
        newP = newHead;
        while(p!=NULL)
        {
            if(p->random==NULL)
                newP->random=NULL;
            else
                newP->random = a[(s.lower_bound(make_pair(p->random, -1)))->second];
            newP = newP->next;
            p=p->next;
        }
     return newHead;   
    }
    
};