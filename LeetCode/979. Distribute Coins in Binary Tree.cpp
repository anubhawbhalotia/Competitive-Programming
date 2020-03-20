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
    int ans;
public:
    int trav(TreeNode* p)
    {
        if(!p)
            return 0;
        int l = trav(p->left);
        int r = trav(p->right);
        ans += abs(l) + abs(r);
        return l + r + p->val - 1;         ;
    }
    int distributeCoins(TreeNode* root) {
        ans = 0;
        trav(root);
        return ans;   
    }
};