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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur=root;
        if(root==NULL)
            return root;
        while(true)
        {
            if(((p -> val)>=(cur -> val) && (q -> val)<=(cur -> val)) || 
               ((p -> val)<=(cur -> val) && (q -> val)>=(cur -> val)))
                break;
            
            if(p -> val > cur -> val)
            {
                if(cur->right==NULL)
                    return cur;
                cur=cur->right;
            }
            else
            {
                if(cur->left==NULL)
                    return cur;
                cur=cur->left;
            }
        }
        return cur;
    }
};