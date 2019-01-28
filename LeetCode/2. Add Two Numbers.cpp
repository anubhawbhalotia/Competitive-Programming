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


    	int ans=l1->val+l2->val;
    	ListNode *l3= new ListNode(ans%10);
    	ListNode *start=l3;
    	l1=l1->next;
    	l2=l2->next;
    	int carry=ans/10;
        while(l1!=NULL || l2!=NULL)
        {
        	if(l1==NULL)
        	{	
        		ans=l2->val + carry;
        		l2=l2->next;
        	}
        	else if(l2==NULL)
        	{
        		ans=l1->val + carry;
        		l1=l1->next;
        	}
        	else
        	{
        		ans=l1->val + l2->val + carry;
        		l1=l1->next;
        		l2=l2->next;       
        	}
        	carry=0;
        	l3->next=new ListNode(ans%10);
        	l3=l3->next;
      		carry=ans/10;
        }
        if(carry)
        {
        	l3->next=new ListNode(carry);
        }
        return start;
        
    }
};