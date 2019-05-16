class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int i = s.length() - 1, c = 0;
        string a = "", ans = "";
        while(i >= 0)
        {
            if(s[i] != '-')
            {
                if(s[i] >= 97 && s[i] <= 122)
                    a += (s[i] - 32);
                else
                    a += s[i];
                if(a.length() == k)
                {
                    if(c != 0)
                        ans += '-';
                    ans += a;
                    c++;
                    a = "";
                }
            }
            i--;
        } 
        if(a != "")
        {
            if(c != 0)
                ans += '-';
            ans += a;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};