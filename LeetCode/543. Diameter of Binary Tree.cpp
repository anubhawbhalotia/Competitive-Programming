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
    int inorder(TreeNode *root, int &ans)
    {
        if(root == NULL)
        {
            return 0;
        }
        int l = inorder(root->left, ans), r = inorder(root->right, ans);
        ans = (root -> right != NULL || root ->left != NULL) ? max(ans, l + r): ans;
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        inorder(root, ans);
        return ans;
    }
};