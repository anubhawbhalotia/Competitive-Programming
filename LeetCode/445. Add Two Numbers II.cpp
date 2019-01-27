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
        ListNode *p,*prev;
        p=l1;
        vector <int> a,b;
        while(p!=NULL)
        {
            a.push_back(p->val);
            p=p->next;
        }
        p=l2;
        while(p!=NULL)
        {
            b.push_back(p->val);
            p=p->next;
        }
        int x=a.size()-1;
        int y=b.size()-1;
        int last=0, c=0;
        while(x!=-1 && y!=-1)
        {
            int sum=a[x]+b[y]+last;
            p=new struct ListNode(sum%10);
            last=sum/10;
            if(c==0)
            {
                p->next=NULL;
            }
            else
            {
                p->next=prev;
            }
            prev=p;
            x--;
            y--;
            c++;
        }
        while(x!=-1)
        {
            int sum=a[x]+last;
            p=new struct ListNode(sum%10);
            last=sum/10;
            p->next=prev;
            prev=p;
            x--;
        }
        while(y!=-1)
        {
            int sum=b[y]+last;
            p=new struct ListNode(sum%10);
            last=sum/10;
            p->next=prev;
            prev=p;
            y--;
        }
        while(last!=0)
        {
            p=new struct ListNode(last%10);
            last=last/10;
            p->next=prev;
            prev=p;
        }
        return p;
    }
};