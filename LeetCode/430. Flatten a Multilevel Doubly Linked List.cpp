/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* traverse(Node* p)
    {
        Node* temp = NULL;
        while(1)
        {
            if(p->child)
            {
                temp = p->next;
                p->next = p->child;
                p->next->prev = p;
                p->child = NULL;
                p = traverse(p->next);
                if(!p)
                    return NULL;
                p->next = temp;
                if(temp)
                {
                    temp->prev = p;
                    p = temp;
                    continue;
                }
                else
                    return NULL;
            }
            if(!p->next)
                return p;
            p = p->next;
        }
        return p;
    }
    Node* flatten(Node* head) {
        if(head == NULL)
            return NULL;
        traverse(head);
        return head;
    }
};