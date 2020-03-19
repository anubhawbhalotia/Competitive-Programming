class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        if(n == 0 || m == 0 || n < m)
            return 0;
        vector<vector<long long>> DP(m + 1, vector<long long>(n + 1, 0));
        for(int i = 0; i < n + 1; i++)
        {
            DP[m][i] = 1;
        }
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1 - (m - i - 1); j >= 0; j--)
            {
                if(t[i] == s[j])
                    DP[i][j] = DP[i + 1][j + 1];
                DP[i][j] += DP[i][j + 1];
            }
        }
        return DP[0][0];
    }
};