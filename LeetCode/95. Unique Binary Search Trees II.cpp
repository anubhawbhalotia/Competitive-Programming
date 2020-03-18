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
    vector<vector<vector<TreeNode*>>> DP;
public:
    void buildTree(int l, int r)
    {
        if(l > r)
            return ;
        if(!DP[l][r].empty())
            return ;
        for(int i = 0; i < r - l + 1; i++)
        {
            buildTree(l, l + i - 1);
            vector<TreeNode*> &left = DP[l][l + i - 1]; 
            buildTree(l + i + 1, r);
            vector<TreeNode*> &right = DP[l + i + 1][r];
            if(left.empty() == 1 && right.empty() == 1)
            {
                DP[l][r].push_back(new TreeNode(l + i));
            }
            else if(right.empty())
            {
                for(int k = 0; k < left.size(); k++)
                {
                    TreeNode *temp = new TreeNode(l + i);
                    temp->left = left[k];
                    temp->right = NULL;
                    DP[l][r].push_back(temp);
                }
            }
            else if(left.empty())
            {
                for(int k = 0; k < right.size(); k++)
                {
                    TreeNode *temp = new TreeNode(l + i);
                    temp->left = NULL;
                    temp->right = right[k];
                    DP[l][r].push_back(temp);
                }
            }
            else
            {
                for(int j = 0; j < left.size(); j++)
                {
                    for(int k = 0; k < right.size(); k++)
                    {
                        TreeNode *temp = new TreeNode(l + i);
                        temp->left = left[j];
                        temp->right = right[k];
                        DP[l][r].push_back(temp);
                    }
                }
            }
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        DP.resize(n + 2, vector<vector<TreeNode*>> (n + 2));
        buildTree(1, n);
        return DP[1][n];
    }
};