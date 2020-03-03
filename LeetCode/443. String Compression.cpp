class Solution {
public:
    string custom_itoa(int c)
    {
        string ans = "";
        while(c)
        {
            ans += ((c%10)+48);
            c /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int compress(vector<char>& chars) {
        int x = -1, c = 1, i = 1;
        for(i = 1; i < chars.size(); i++)
        {
            if(chars[i] == chars[i-1])
            {
                c++;
                continue;
            }
            chars[++x] = chars[i-1];
            if(c-1)
                for(auto j : custom_itoa(c))
                    chars[++x] = j;
            c = 1;
        }
        chars[++x] = chars[i - 1];
        if(c-1)
            for(auto j : custom_itoa(c))
                chars[++x] = j;
        chars.resize(x + 1);
        return x + 1;
    }
};