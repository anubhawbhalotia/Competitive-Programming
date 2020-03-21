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
    vector<string> ans;
public:
    string itos(int a)
    {
        if(a == 0)
            return "0";
        int flag = 0;
        if(a < 0)
            flag = 1;
        string str = "";
        a = abs(a);
        while(a)
        {
            str += (a % 10) + 48;
            a /= 10;
        }
        if(flag)
            str += '-';
        reverse(str.begin(), str.end());
        return str;
    }
    void trav(TreeNode* p, string s)
    {
        if(p == NULL)
            return;
        s += itos(p->val);    
        if(p->left != NULL || p->right != NULL)
        {
            s += "->";
            trav(p->left, s);
            trav(p->right, s);
        }
        else
            ans.push_back(s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        trav(root, s);
        return ans;
    }
};