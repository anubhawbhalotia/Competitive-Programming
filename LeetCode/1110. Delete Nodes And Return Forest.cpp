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
    void traverse(TreeNode *q, TreeNode *p, unordered_set <int> &s, vector <TreeNode*> &r)
    {
        if(!q)
            return;
        if(s.find(q->val) != s.end())
        {
            if(p)
            {
                if(p->left == q)
                    p->left = NULL;
                else
                    p->right = NULL;
            }
            if(q->left)
                traverse(q->left, NULL, s, r);
            if(q->right)
                traverse(q->right, NULL, s, r);
        }   
        else
        {
            if(p == NULL)
            {
                r.push_back(q);
            }
            traverse(q->left, q, s, r);
            traverse(q->right, q, s, r);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s;
        for(auto i : to_delete)
            s.insert(i);
        vector <TreeNode*> r;
        traverse(root, NULL, s, r);
        return r;
    }
};