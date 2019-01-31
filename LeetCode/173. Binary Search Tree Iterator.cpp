/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack <TreeNode*> path;
    stack <int> type;
    void traverse(TreeNode* node)
    {
        if(node==NULL)
            return;
        if(node->left==NULL)
        {
            path.push(node);
            type.push(1);
            return;
        }
        path.push(node);
        type.push(0);
        traverse(node->left);
    }
    BSTIterator(TreeNode* root) {
        traverse(root);
    }
    void traverseNext()
    {
        while(type.size())
        {
            int typ=type.top();
            if(typ==0)
            {
                type.pop();
                type.push(1);
                return;
            }
            if(typ==1)
            {
                if(path.top()->right!=NULL)
                {
                    TreeNode* q=path.top();
                    type.pop();
                    path.pop();
                    traverse(q->right);
                    return;
                }
                else
                {
                    path.pop();
                    type.pop();
                    continue;
                }
            }
            path.pop();
            type.pop();
        }
        
    }
    /** @return the next smallest number */
    int next() {
        int ans=path.top()->val;
        // type.pop();
        // type.push(1);
        traverseNext();
        return ans;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(type.size()==0)
            return false;
        else
            return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */