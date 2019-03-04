class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> ans;
        int g[130]={};
        for(int i = 0; i!=p.length(); i++)
            g[p[i]]++;
        int st = 0, en = -1;
        while((en+1)!=s.length())
        {
            en++;
            if(g[s[en]])
            {
                g[s[en]]--;
                if(en-st+1 == p.length())
                {
                    ans.push_back(st);
                    g[s[st]]++;
                    st++;
                }
            }
            else
            {
                g[s[st]]++;
                st++;
                en--;
            }
        }
        return ans;
    }
};