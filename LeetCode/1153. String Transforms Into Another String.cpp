class Solution {
public:
    bool canConvert(string str1, string str2) {
        vector <char> m(27, 26);       
        int z = 26;
        for(int i = 0; i < str1.length(); i++)
        {
            if(m[str1[i] - 97] == 26)
            {
                z--;
                m[str1[i] - 97] = str2[i] - 97;
            }
            else if(m[str1[i] - 97] != str2[i] - 97)
                return false;
        }
        vector <bool> flag(27, false);
        flag[26] = 1;
        for(int i  = 0; i < 26; i++)
        {
            if(flag[i])
                continue;
            if(m[i] == i)
            {
                flag[i] = 1;
                continue;
            }
            int temp = i, c = 0;
            unordered_set <int> s;
            while(temp != 26)
            {
                if(s.find(temp) != s.end())
                {
                    if(i == temp && z == 0)
                        return false;
                    break;
                }
                flag[temp] = 1;
                s.insert(temp);
                temp = m[temp];
            }
        }
        return true;
    }
};