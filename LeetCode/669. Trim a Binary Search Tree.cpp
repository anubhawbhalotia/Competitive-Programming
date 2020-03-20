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
    void trav(TreeNode* &p, int L, int R)
    {
        if(p == NULL)
        {
            return ;
        }
        trav(p->left, L, R);
        trav(p->right, L, R);
        if(p->val >= L && p->val <= R)
        {
            return ;
        }
        if(p->left)
            p = p->left;
        else
            p = p->right;
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        trav(root, L, R);
        return root;
    }
};