class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, r = 0, l = 0;
        for(int i = 0; i < (int)s.length(); i++)
        {
            (s[i] == ')') ? r++ : l++;
            if(l == r)
                ans = max(ans, l + r);
            if(r > l)
            {
                l = 0;
                r = 0;
            }
            
        }
        l = 0; r = 0;
        for(int i = (int)s.length() - 1; i >= 0; i--)
        {
            (s[i] == ')') ? r++ : l++;
            if(l == r)
                ans = max(ans, l + r);
            if(l > r)
            {
                r = 0;
                l = 0;
            }
        }
        return ans;
    }
};