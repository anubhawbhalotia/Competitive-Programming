/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class segTree {
    vector <int> t;
public:
    segTree()
    {
        t.resize(2500, 0);
    }
    void build(vector <int> &a, int l, int r, int node)
    {
        if(l == r)
        {
            t[node] = l;
            return;
        }
        build(a, l, (l + r) / 2, node * 2 + 1);
        build(a, (l + r) / 2 + 1, r, node * 2 + 2);
        t[node] = (a[t[node * 2 + 1]] > a[t[node * 2 + 2]]) ? t[node * 2 + 1] : t[node * 2 + 2];
    }
    int query(vector<int> &a, int st, int en, int node, int l, int r)
    {
        if(st > r || en < l)
            return INT_MIN;
        if(l >= st && r <= en)
            return t[node];
        int left = query(a, st, en, node * 2 + 1, l, (l + r) / 2);
        int right = query(a, st, en, node * 2 + 2, (l + r) / 2 + 1, r);
        if(left != INT_MIN && right != INT_MIN)
        {
            return (a[left] > a[right]) ? left : right;
        }
        return (left != INT_MIN) ? left : right;
    }
};
class Solution {
    segTree tree;
public:
    TreeNode* divCon(vector<int> &a, int l, int r)
    {
        if(l > r)
            return NULL;
        int q = tree.query(a, l, r, 0, 0, (int)a.size() - 1);
        TreeNode* temp = new TreeNode(a[q]);
        temp->left = divCon(a, l, q - 1);
        temp->right = divCon(a, q + 1, r);
        return temp;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        tree.build(nums, 0, (int)nums.size() - 1, 0);
        return divCon(nums, 0, (int)nums.size() - 1);
    }
};