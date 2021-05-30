/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Time : O(n)
// Space : O(n)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return traverse(root, targetSum);
    }
private:
    bool traverse(TreeNode *p, int s) {
        if (p == NULL) {
            return false;
        }
        s -= p->val;
        if (s == 0 && p->left == NULL && p->right == NULL) {
            return true;
        }
        return traverse(p->left, s) | traverse(p->right, s);
    }
};