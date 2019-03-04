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
    string itoa(int num)
    {
        string s;
        if(num==0)
            return "0";
        int m = 1;
        if(num < 0)
        {
            num*=-1;
            m=-1;
        }
        while(num!=0)
        {
            s+=(num%10)+48;
            num /= 10;
        }
        if(m==-1)
            s+='-';
        reverse(s.begin(), s.end());
        return s;
    }
    int atoi(string s, int begin, int end)
    {
        int ans = 0, m=1;
        if(s[begin] == '-')
        {
            begin++;
            m=-1;
        }
        for(int i = begin; i!=end; i++)
            ans = (ans*10) + (s[i]-48);
        return ans*m;
    }
    string serialize(TreeNode* root) {
        string s = "";
        if(root==NULL)
            return s;
        s = itoa(root->val);
        string l = serialize(root->left);
        string r = serialize(root->right);
        // cout<<"a"<<l<<" "<<r<<endl;
        if(l=="" && r=="")
        {
            // cout<<s<<endl;
            return s;
        }
        else
        {
            s = s + "(" + l + "," + r + ")";
            // cout<<s<<endl;
            return s;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data,  int begin=0, int end = 0, TreeNode* node = NULL) {
        if(data == "")
            return NULL;
        // cout<<begin<<" "<<end<<endl;
        int st = begin, en = begin;
        if(end==0)
            end = data.length();
        while(data[en] != '(' && data[en] != ',' && en!=data.length() && data[en] != ')')
            en++;
        if(node == NULL)
            node = new TreeNode(atoi(data, st, en));
        else
            node->val = atoi(data, st, en);
        if(data[en] == '(')
        {
          int   c=0;
            en++;
            st = en;
            while(1)
            {
                if(c==0 && data[en]==',')
                    break;
                if(data[en] == '(')
                    c++;
                if(data[en] == ')')
                    c--;
                en++;
            }
            if(en>st)
            {
                node->left = new TreeNode(0);
                deserialize(data, st, en, node->left);
            }
            en++;
            st = en;
            en = end;
            while(data[en-1] != ')')
                en--;
            en--;
            if(en>st)
            {
                node->right = new TreeNode(0);
                deserialize(data, st, en, node->right);
            }
        }
        return node;
            
            
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));