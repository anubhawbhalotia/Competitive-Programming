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
        if(p == NULL)
            return 0;
        int l = trav(p->left);
        int r = trav(p->right);
        int temp = p->val;
        if(l > 0)
            temp += l;
        if(r > 0)
            temp += r;
        ans = max(ans, temp);
        return max(0, max(0, max(l, r)) + p->val);
    }
    int maxPathSum(TreeNode* root) {
        ans = -100000;
        trav(root);
        return ans;
    }
};