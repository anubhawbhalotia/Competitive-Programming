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
    void trav(TreeNode* root, TreeNode* &last)
    {
        if(!root)
            return;
        if(root)
            last = root;
        swap(root->left, root->right);
        trav(root->right, last);
        last->right = root->left;
        root->left = NULL;
        trav(last->right, last);
    }
    void flatten(TreeNode* root) {
        trav(root, root);
    }
};a