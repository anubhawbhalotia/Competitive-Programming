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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        TreeNode *p=root;
        
        queue <TreeNode*> q;
        q.push(p);
        int l=0;
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        while(1)
        {
            int size = q.size();
            vector <int> v(size);
            int c=0;
            for(int j=0;j!=size;j++)
            {
                if(l%2==0)
                {
                    v[c] = (q.front())->val;
                }
                else
                {
                    v[size-c-1] = (q.front())->val;
                }
                if((q.front())->left!=NULL)
                    q.push((q.front())->left);
                if((q.front())->right!=NULL)
                    q.push((q.front())->right);
                q.pop();
                c++;
            }
            ans.push_back(v);
            if(q.empty())
                break;
            l++;
        }
        return ans;
    }
};