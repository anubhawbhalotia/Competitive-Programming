typedef struct node {
    string b;
    struct node* next;
    node(string s)
    {
        b = s;
        next = NULL;
    }
}node;
class Solution {
    unordered_set <string> a;
    vector<vector<node*>> DP;
    vector<int> DP_size;
public:
    void dp(string &s, int x)
    {
        if(DP_size[x] != -1)
        {
            return;
        }
        vector <node*> ans;
        if(x < (int)s.length())
        {
            node* temp;
            string word = "";
            for(int i = x; (int)i < s.length(); i++)
            {
                word += s[i];
                if(a.find(word) != a.end())
                {                        
                    dp(s, i + 1);
                    vector <node*> &r = DP[i + 1];
                    if(!r.empty())
                    {
                        for(int j = 0; j < (int)r.size(); j++)
                        {
                            temp = new node(word);
                            temp->next = r[j];
                            ans.push_back(temp);
                        }
                    }
                    else if(i == (int)s.length() - 1)
                    {
                        temp = new node(word);
                        ans.push_back(temp);
                    }
                }
            }
        }
        DP[x] = ans;
        DP_size[x] = ans.size();
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto i : wordDict)
        {
            a.insert(i);
        }
        DP.resize((int)s.length() + 2);
        DP_size.resize((int)s.length() + 2, -1);
        dp(s, 0);
        vector <node*> &ans = DP[0];
        string sen;
        vector<string> r;
        for(int i = 0; i < (int)ans.size(); i++)
        {
            sen = "";
            while(1)
            {
                sen += ans[i]->b;
                ans[i] = ans[i]->next;
                if(ans[i])
                    sen += ' ';
                else
                    break;
            }
            r.push_back(sen);
        }
        return r;
    }
};