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
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return ans;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode * c = s.top();
        while(!s.empty())
        {
            while(c != NULL && c->left != NULL)
            {
                c = c->left;
                s.push(c);
            }
            ans.push_back(s.top()->val);
            c = s.top()->right;
            s.pop();
            if(c)
            {
                s.push(c);
            }
        }
        return ans;
    }
}