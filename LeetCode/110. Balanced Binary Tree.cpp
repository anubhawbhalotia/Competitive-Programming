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
    bool trav(TreeNode* p, int &h)
    {
        if(!p)
            return 1;
        int l_h = 0, r_h = 0;
        bool ans = trav(p->left, l_h) & trav(p->right, r_h) & (abs(l_h - r_h) <= 1);
        h = max(l_h, r_h) + 1; 
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        int h = 0;
        return trav(root, h);
    }
};