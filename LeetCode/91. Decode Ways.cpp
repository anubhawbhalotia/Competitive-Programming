class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector <int> DP(n + 2, 1);
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '0')
            {
                DP[i] = 0;
                continue;
            }
            DP[i] = DP[i + 1];
            if(((s[i] - 48) * 10) + (s[i + 1] - 48) <= 26 && i < n - 1)
            {
                DP[i] += DP[i + 2];
            }
        }
        return DP[0];
    }
};