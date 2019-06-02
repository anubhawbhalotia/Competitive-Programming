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
    int n;
public:
    int search(TreeNode *root)
    {
        int v= 0;
        if(root->left != NULL)
            v = search(root->left);
        if(n == 0)
            return v;
        n-- ;
        if(n == 0)
            return root->val;
        if(root->right != NULL)
            v = search(root->right);
        return v;
    }
    int kthSmallest(TreeNode* root, int k) {
        n = k;
        return search(root);    
    }
};