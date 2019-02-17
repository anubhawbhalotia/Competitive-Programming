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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue <TreeNode*> q;
        if(root==NULL)
            return ans;
        q.push(root);
        int sz, i;
        while(!q.empty())
        {
            sz = q.size();
            vector <int> temp;
            for(i = 0; i!=sz; i++)
            {
                TreeNode* d = q.front();
                if(d->left!=NULL)
                    q.push(d->left);
                if(d->right!=NULL)
                    q.push(d->right);
                temp.push_back(d->val);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};