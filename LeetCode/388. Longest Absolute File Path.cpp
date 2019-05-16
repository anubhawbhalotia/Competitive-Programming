class Solution 
{
public:
    typedef struct node 
    {
        int l;
        bool isFile;
        vector <struct node*> child;
        struct node* parent;
    }node;
    node *root, *p;
    Solution()
    {
        root = new node;
        root->parent = NULL;
        root->l = 0;
        root->isFile = false;
        p = root;
    }
    bool checkIsFile(string s)
    {
        int i = 0;
        while(i != s.length())
        {
            if(s[i++] == '.')
                return true;
        }
        return false;
    }
    int dfs(node* p)
    {
        if(p->child.size() == 0)
        {
            if(p->isFile == false)
                p->l = 0;
            return p->l;
        }
        int ans = 0;
        for(int i = 0; i != p->child.size(); i++)
            ans = max(ans, dfs(p->child[i]));
        return ((ans != 0) ? ans + p->l + 1 : 0);
    }
    int lengthLongestPath(string input) 
    {
        int i = 0, level = 1, lastLevel = 0;
        string str = "";
        while(i != input.length() + 1)
        {
            if(i <= input.length() - 1 && input[i] != '\n')
                str += input[i++];
            else
            {
                while(level <= lastLevel)
                {
                    p = p->parent;
                    lastLevel--;
                }
                node* temp = new node;
                temp->parent = p;
                temp->l = str.length();
                temp->isFile = checkIsFile(str);
                (p->child).push_back(temp);
                p = temp;
                lastLevel = level;
                level = 1;
                while(i < input.length() - 1)
                {
                    if(input[i] == '\t')
                        level++;
                    else if(i<=input.length()-4 && input[i] == ' ' && input[i+1] == ' '
                           && input[i+2] == ' ' && input[i+3] == ' ')
                    {
                        i+=3;
                        level++;
                    }
                    else if(input[i] != '\n')
                        break;
                    i++;
                    if(level == lastLevel + 1)
                        break;
                }
                str = "";
                if(i == input.length())
                    break;
            }
        }
        int ans = dfs(root);
        if(ans)
            ans--;
        return ans;
    }
};