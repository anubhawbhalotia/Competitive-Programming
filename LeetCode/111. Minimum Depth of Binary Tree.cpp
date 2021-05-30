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
    int minDepth(TreeNode* root) {
        if (root != NULL) {
            return traverse(root, 10e5+4);
        }
        return 0;
    }
private:
    int traverse(TreeNode *p, int m) {
        if (m == 1 || p->left == NULL && p-> right == NULL) {
            return 1;
        }
        if (p->left != NULL) {
            m = min(traverse(p->left, m - 1) + 1, m);
        }
        if (p->right != NULL) {
            m = min(traverse(p->right, m - 1) + 1, m);
        }
        return m;
    }
};