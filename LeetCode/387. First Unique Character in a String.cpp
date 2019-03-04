class Solution {
public:
    int firstUniqChar(string s) {
        int f[26] = {};
        list <int> l;
        list <int> :: iterator it[26];
        for(int i = 0; i!=s.length(); i++)
        {       
            f[s[i]-97]++;
            if(f[s[i]-97] == 1)
            {
                l.push_back(i);
                it[s[i]-97] = --l.end();
            }
            else if(f[s[i]-97] == 2)
                l.erase(it[s[i]-97]);
        }
        if(!l.empty())
            return l.front();
        return -1;
        
    }
};