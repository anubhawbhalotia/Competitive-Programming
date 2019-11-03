/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *p = new TreeNode(0);
    TreeNode *head = p, *nextT1, *nextT2;
    int t1val, t2val;
    void inorder(TreeNode *t1, TreeNode* t2, TreeNode* p)
    {
        nextT1 = (t1 != NULL && t1->left != NULL) ? t1->left : NULL;
        nextT2 = (t2 != NULL && t2->left != NULL) ? t2->left : NULL;
        t1val = (t1 != NULL) ? t1->val : 0;
        t2val = (t2 != NULL) ? t2->val : 0;
        p->val = t1val + t2val;
        if(nextT1 != NULL || nextT2 != NULL)
        {
            p->left = new TreeNode(0);
            inorder(nextT1, nextT2, p->left);
        }
        nextT1 = (t1 != NULL && t1->right != NULL) ? t1->right : NULL;
        nextT2 = (t2 != NULL && t2->right != NULL) ? t2->right : NULL;
        if(nextT1 != NULL || nextT2 != NULL)
        {
            p->right = new TreeNode(0);
            inorder(nextT1, nextT2, p->right);
        }
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL)
            return NULL;
        inorder(t1, t2, p);
        return head;
    }
};