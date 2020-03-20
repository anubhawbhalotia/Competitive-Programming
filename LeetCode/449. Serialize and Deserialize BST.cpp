/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string itoa(int a)
    {
        string str = "";
        while(a)
        {
            str += (a % 10) + 48;
            a /= 10;
        }
        reverse(str.begin(), str.end());
        return str;
    }
    void preTrav(TreeNode* p, string &str)
    {
        if(!p)
            return ;
        str += itoa(p->val) + ' ';
        preTrav(p->left, str);
        preTrav(p->right, str);
    }
    
    string serialize(TreeNode* root) {
        string str = "";
        preTrav(root, str);
        return str;
    }
    
    vector <int> parse(string &str, int &l, int &r)
    {
        int temp = 0;
        vector<int> ans;
        for(int i = l; i < r; i++)
        {
            if(str[i] != ' ')
            {
                temp = (temp * 10) + (str[i] - 48);
            }
            else
            {
                ans.push_back(temp);
                temp = 0;
            }
        }
        return ans;
    }
    // Decodes your encoded data to tree.
    void divCon(unordered_map <int,int> &m, vector<int> &pre, int l, int r, int &x, TreeNode* p)
    {
        if(x < (int)pre.size() - 1)
        {
            if(m[pre[x + 1]] < m[pre[x]] && m[pre[x + 1]] >= l)
            {
                p->left = new TreeNode(pre[++x]);
                divCon(m, pre, l, pre[x - 1] - 1, x, p->left);
            }
        }
        if(x < (int)pre.size() - 1)
        {
            if(m[pre[x + 1]] > m[pre[x]] && m[pre[x + 1]] <= r)
            {
                p->right = new TreeNode(pre[++x]);
                divCon(m, pre, pre[x - 1] + 1, r, x, p->right);
            }
        }
    }
    TreeNode* deserialize(string data) {
        if(data.length() == 0)
            return NULL;
        int v = 0;
        int n = data.length();
        vector<int> pre = parse(data, v, n);
        vector<int> in = pre;
        sort(in.begin(), in.end());
        unordered_map <int, int> m;
        for(int i = 0; i < (int)in.size(); i++)
        {
            m[in[i]] = i;
        }
        int x = 0;
        TreeNode *temp = new TreeNode(pre[0]);
        divCon(m, pre, 0, (int)pre.size() - 1, x, temp);
        return temp;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));