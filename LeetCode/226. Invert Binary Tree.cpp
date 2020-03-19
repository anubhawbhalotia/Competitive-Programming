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
    TreeNode* invertTree(TreeNode* root) {
        stack <TreeNode*> s;
        if(root)
            s.push(root);
        while(!s.empty())
        {
            TreeNode* temp = s.top();
            s.pop();
            swap(temp->left, temp->right);
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
        }
        return root;
    }
};