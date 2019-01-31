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
    int validate(TreeNode* node,  long long l, long long r)
    {
        if(node==NULL)
            return 1;
        if(node->val>r || node->val < l)
            return 0;
        return min(validate(node->left, l, (long long)node->val-1),
                  validate(node->right, (long long)node->val+1, r));
        
    }
    bool isValidBST(TreeNode* root) {
        return validate(root, (long long )INT_MIN, (long long)INT_MAX)==0?false:true;
    }
};