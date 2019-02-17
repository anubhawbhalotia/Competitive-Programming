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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int sz = inorder.size();
        if(sz == 0)
            return NULL;
        TreeNode *head = new TreeNode(postorder[sz-1]);
        set < pair < int, int> > a;
        TreeNode *c[sz];
        set <int> d;
        for(int i = 0; i<inorder.size(); i++)
            a.insert(make_pair(inorder[i], i));
        int pos = (a.lower_bound(make_pair(head->val, -1)))->second;
        c[pos] = head;
        d.insert(pos);
        set <int> :: iterator x, y, it;
        for(int i = sz-2; i>=0; i--)
        {
            int pos = (a.lower_bound(make_pair(postorder[i], -1)))->second;
            it = d.lower_bound(pos);
            y = it;
            it--;
            x = it;
            if(y!=d.end() && c[*y]->left==NULL)
            {
                c[*y]->left = new TreeNode(postorder[i]);
                c[pos] = c[*y]->left;
            }
            else
            {
                c[*x]->right = new TreeNode(postorder[i]);
                c[pos] = c[*x]->right;
            }
            d.insert(pos);
        }
        return head;
    }
};