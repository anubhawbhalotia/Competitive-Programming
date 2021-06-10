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
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        return traverse(root, target);
    }
    int traverse(TreeNode *p, double target) {
        if (p == NULL) {
            return INT_MAX;
        }
        int ans = p->val;
        int temp = INT_MAX;
        if ((double)(p->val) > target) {
            temp = traverse(p->left, target);
        } else if ((double)(p->val) < target) {
            temp = traverse(p->right, target);
        }
        if (temp != INT_MAX) {
            if (abs(target-(double)temp) < abs(target-(double)(p->val))) {
                ans = temp;
            }
        }
        return ans;
    }   
};