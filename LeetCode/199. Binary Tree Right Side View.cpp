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
    vector<int> ans;
public:
    int trav(TreeNode* p, int x)
    {
        if(!p)
            return 0;
        if(x <= 0)
            ans.push_back(p->val);
        x = max(x, trav(p->right, x - 1) + 1);
        x = max(x, trav(p->left, x - 1) + 1);
        return x;
    }
    vector<int> rightSideView(TreeNode* root) {
        trav(root, 0);
        return ans;
    }
};