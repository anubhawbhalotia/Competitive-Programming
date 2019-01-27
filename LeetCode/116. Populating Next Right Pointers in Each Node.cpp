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
    void traverse(TreeLinkNode *node)
    {
        if(node==NULL || node->left==NULL)
            return ;
        node->left->next = node->right;
        if(node->next!=NULL)
        {
            node->right->next = node->next->left;
        }
        traverse(node->left);
        traverse(node->right);
    }
    void connect(TreeLinkNode *root) {
        traverse(root);
    }
    
};