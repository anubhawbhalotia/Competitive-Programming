class Solution {
public:
    short int findF(string &s)
    {
        char m = 'z' + 1;
        short int ans = 0;
        for(int i = 0; i != s.length(); i++)
        {
            if(s[i] < m)
            {
                m = s[i];
                ans = 1;
            }
            else if(s[i] == m)
            {
                ans++;
            }
        }
        return ans;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector <int> ans, z(12, 0);
        for(int i = 0; i != words.size(); i++)
        {
            z[findF(words[i])]++;
        }
        for(int i = z.size() - 2; i >= 0; i--)
        {
            z[i] = z[i + 1] + z[i];
        }
        for(int i = 0; i != queries.size(); i++)
        {
            ans.push_back(z[findF(queries[i]) + 1]);
        }
        return ans;
    }
};