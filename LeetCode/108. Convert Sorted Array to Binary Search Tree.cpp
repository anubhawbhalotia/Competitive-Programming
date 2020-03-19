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
    TreeNode* divCon(int l, int r, vector<int>& nums)
    {
        if(l > r)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(nums[(l + r) / 2]);
        root->left = divCon(l, (l + r) / 2 - 1, nums);
        root->right = divCon((l + r) / 2 + 1, r, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return divCon(0, (int)nums.size() - 1, nums);
    }
};