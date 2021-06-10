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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *temp;
        while(head != NULL && head->val == val) {
            temp = head;
            head = head->next;
            delete(temp);
        }
        ListNode *p = head;
        while(p != NULL) {
            while(p->next != NULL && p->next->val == val) {
                temp = p->next;
                p->next = p->next->next;
                delete(temp);
            }
            p = p->next;
        }
        return head;
    }
};