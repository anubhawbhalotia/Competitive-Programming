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
    unordered_map <int, int> m;
    int ans;
public:
    void trav(TreeNode* p, int &s, int t)
    {
        if(!p)
            return ;
        t += p->val;
        if(m[t - s] > 0)
            ans += m[t - s];
        m[t]++;
        trav(p->left, s, t);
        trav(p->right, s, t);
        m[t]--;
    }
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        m[0] = 1;
        trav(root, sum, 0);
        return ans;
    }
};