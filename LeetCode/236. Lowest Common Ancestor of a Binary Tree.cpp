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
    TreeNode* ans = NULL;
    int traverse(TreeNode* node, int p, int q)
    {
        int c = 0;
        if(node==NULL)
            return c;
        if(node->val == p)
            c++;
        if(node->val == q)
            c++;
        c += traverse(node->left, p, q);
        if(c==2)
        {
            ans = node;
            return -1;
        }
        c += traverse(node->right, p, q);
        if(c==2)
        {
            ans = node;
            return -1;
        }
        return c;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root, p->val, q->val);
        return ans;
    }
};