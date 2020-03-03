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
    void solve(int st, int en, TreeNode *p, int &x, vector<int> &pre, unordered_map <int,int> &m)
    {
        if(x+1 <= pre.size()-1)
        {
            if(m[pre[x+1]] < m[pre[x]] && m[pre[x+1]] >= st)
            {
                p->left = new TreeNode(pre[++x]);
                solve(st, m[pre[x-1]] - 1, p->left, x, pre, m);
            }
        }
        if(x+1 <= pre.size()-1)
        {
            if(m[pre[x+1]] > m[pre[x]] && m[pre[x+1]] <= en)
            {
                p->right = new TreeNode(pre[++x]);
                solve(m[pre[x-1]] + 1, en, p->right, x, pre, m);
            }
        }
        
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        unordered_map <int,int> m;
        int x = 0;
        for(int i = 0; i < in.size(); i++)
        {
            m[in[i]] = x++;
        }
        if(n == 0)
            return NULL;
        TreeNode *root = new TreeNode(pre[0]);
        x = 0;
        solve(0, n - 1, root, x, pre, m);
        return root;   
    }
};