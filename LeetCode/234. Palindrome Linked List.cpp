/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return true;
        }
        //find mid
        ListNode *p = head, *q = head, *temp, *r, *d;
        while(q != NULL && q->next != NULL && q->next->next != NULL) {
            p = p->next;
            q = q->next->next;
        }
        cout<<"1"<<endl;
        q = p;
        r = q;
        temp = NULL;
        q = q->next;
        while(q != NULL) {
            d = q->next;
            q->next = temp;
            temp = q;
            q = d;
        }
        cout<<"1"<<endl;
        r->next = temp;
        
        p = head;
        q = head;
        while(q != NULL && q->next != NULL && q->next->next != NULL) {
            p = p->next;
            q = q->next->next;
        }
        q = p->next;
        p = head;
        while(q != NULL) {
            if (p->val != q->val) {
                return false;
            }
            p = p->next;
            q = q->next;
        }
        return true;
    }
};