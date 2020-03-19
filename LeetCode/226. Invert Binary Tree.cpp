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
    void trav(TreeNode* p)
    {
        if(!p)
            return;
        trav(p->left);
        trav(p->right);
        swap(p->left, p->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        trav(root);
        return root;
    }
};