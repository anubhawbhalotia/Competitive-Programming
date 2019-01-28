/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(TreeLinkNode* p)
    {
        if(p==NULL || (p->left==NULL && p->right==NULL))
            return;
        if(p->left!=NULL && p->right!=NULL)
        {
            p->left->next = p->right;
        }
        if(p->next==NULL)
        {
            traverse(p->left);
            traverse(p->right);
            return;
        }
        TreeLinkNode  *c, *d=p->next;
        if(p->right!=NULL)
            c=p->right;
        else 
            c=p->left;
        while(d!=NULL)
        {
            if(d->left!=NULL)
            {
                d=d->left;
                break;
            }
            if(d->right!=NULL)
            {
                d=d->right;
                break;
            }
            d=d->next;
        }
        if(d!=NULL)
            c->next=d;
        traverse(p->left);
        traverse(p->right);
            
        
    }
    void connect(TreeLinkNode *root) {
        for(int i=0;i<5;i++)
        {
            traverse(root);
            traverse(root);
        }
    }
};