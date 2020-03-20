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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> s;
        if(!root)
            return s;
        queue<TreeNode*> q;
        q.push(root);
        int m;
        while(!q.empty())
        {
            m = q.size();
            vector<int> temp;
            while(m--)
            {
                temp.push_back(q.front()->val);
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            s.push_back(temp);
        }
        reverse(s.begin(), s.end());
        return s;
    }
};