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
    int cnt(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return cnt(root->left) + 1 + cnt(root->right);
    }
    int countNodes(TreeNode* root) {
        return cnt(root);
    }
};