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
    int g = 0;
public:
    
    int dfs(TreeNode *root)
    {
        int a = 0, ans = 0;
        if(root->left != NULL)
        {
            a = dfs(root->left);
            if(root->val == root->left->val - 1)
                ans = max(ans, a);
        }
        if(root->right != NULL)
        {
            a = dfs(root->right);
            if(root->val == root->right->val - 1)
                ans = max(ans, a);
        }
        ans++;
        g = max(g, ans);
        return ans;
    }
    int longestConsecutive(TreeNode* root) {
        if(root != NULL)
            dfs(root);
        return g;
    }
};