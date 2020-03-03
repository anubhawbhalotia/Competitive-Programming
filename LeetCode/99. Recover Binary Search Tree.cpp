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
    void traverse(TreeNode *root, TreeNode *&prev, vector<TreeNode*> &ano)
    {
        if(root == NULL)
            return ;
        traverse(root->left, prev, ano);
        if(prev != NULL)
        {
            if(root->val < prev->val)
            {
                if(ano.empty())
                {
                    ano.push_back(prev);
                    ano.push_back(root);
                }
                else
                {
                    ano[1] = root; 
                }
            }
        }
        prev = root;
        traverse(root->right, prev, ano);
    }
    void recoverTree(TreeNode* root) {
        vector <TreeNode*> ano;
        TreeNode *prev = NULL;
        traverse(root, prev, ano);   
        swap(ano[0]->val, ano[1]->val);
    }
};