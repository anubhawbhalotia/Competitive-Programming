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
    int trav(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL)
            return 1;
        if(p == NULL || q == NULL)
            return 0;
        if(p->val != q->val)
            return 0;
        return trav(p->left, q->right) & trav(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return trav(root, root);
    }
};