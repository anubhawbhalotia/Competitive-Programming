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
    bool isEqual(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL)
            return 1;
        if(p != NULL && q != NULL)
        {
            if(p->val == q->val)
            {
                return isEqual(p->left, q->left) && isEqual(p->right, q->right);
            }
            return 0;
        }
        return 0;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isEqual(p, q);
    }
};