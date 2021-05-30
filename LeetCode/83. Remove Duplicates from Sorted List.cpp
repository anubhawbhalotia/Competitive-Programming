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
// Time : O(n)
// Space : O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head, *temp;
        while(p != NULL && p->next != NULL) {
            ListNode* q = p->next;
            while(q != NULL && p->val == q->val) {
                temp = q->next;
                delete q;
                q = temp;
            }
            p->next = q;
            p = p->next;
        }
        return head;
    }
};