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
	int findPreOrder(vector <int> &pre,TreeNode* p)
	{
		if(p==NULL)
			return 0;
		findPreOrder(pre,p->left);
		pre.push_back(p->val);
		findPreOrder(pre,p->right);
		return 1;
	}
    TreeNode* increasingBST(TreeNode* root) {
    	vector <int> pre;
        findPreOrder(pre,root);
        // for(vactor <int> :: iterator it=pre.begin();it!=pre.end();it++)
        // {
        // 	cout<<*it<<" ";
        // }
        // cout<<endl;
        TreeNode *q=new TreeNode(*pre.begin());
        TreeNode *r=q;
        vector <int> :: iterator it=pre.begin()+1;
        for(;it!=pre.end();it++)
        {
        	q->right=new TreeNode(*it);
        	q=q->right;
        }
        return r;
    }
};