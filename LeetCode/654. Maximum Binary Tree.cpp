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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack <TreeNode*> s;
        int n = nums.size();
        s.push(new TreeNode(nums[0]));
        TreeNode* temp, *root;
        for(int i = 1; i < n; i++)
        {
            while(!s.empty())
            {
                if(s.top()->val < nums[i])
                {
                    temp = s.top();
                    s.pop();
                }
                else
                {
                    root = new TreeNode(nums[i]);
                    if(s.empty())
                    {
                        root->left = temp;
                    }
                    else
                    {
                        temp = s.top()->right;
                        s.top()->right = root;
                        root->left = temp;
                    }
                    s.push(root);
                    break;
                }
            }
            if(s.empty())
            {
                root = new TreeNode(nums[i]);
                root->left = temp;
                s.push(root);
            }
        }
        while(!s.empty())
        {
            temp = s.top();
            s.pop();
        }
        return temp;
    }
};