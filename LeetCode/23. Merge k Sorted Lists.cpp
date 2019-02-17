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
    vector <pair < long, long > > h;
    int n;
    void heapify(int i)
    {
        long min = i;
        if((i*2)+1 <= n-1)
        {
            if(h[(i*2)+1].first < h[min].first)
                min = (i*2)+1;
        }
        else
            return;
        if((i*2)+2 <= n-1)
        {
            if(h[(i*2)+2].first < h[min].first)
                min = (i*2)+2;
        }
        if(min==i)
            return;
        long temp = h[min].first;
        h[min].first = h[i].first;
        h[i].first = temp;
        temp = h[min].second;
        h[min].second = h[i].second;
        h[i].second = temp;
        heapify(min);
    }
    void buildHeap()
    {
        for(long i = (n-1)/2; i>=0; i--)
            heapify(i);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head, *prev = NULL, *p;
        for(long i = 0; i!=lists.size(); i++)
        {
            if(lists[i]!=NULL)
                h.push_back(make_pair(lists[i]->val, i));
        }
        n = h.size();
        if(n==0)
            return NULL;
        buildHeap();
        while(n)
        {
            p = new ListNode(h[0].first);
            if(prev!=NULL)
                prev->next = p;
            else
                head = p;
            prev = p;
            lists[h[0].second] = lists[h[0].second] -> next;
            if(lists[h[0].second] == NULL)
            {
                h[0].first = h[n-1].first;
                h[0].second = h[n-1].second;
                n--;
            }
            else
                h[0].first = lists[h[0].second]->val;
            heapify(0);
        }
        return head;
    }
};