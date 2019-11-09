class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        if(m.empty())
            return 0;
        if(m[0].empty())
            return 0;
        vector <int> dp(m[0].size(), 0);
        int prev = 0, temp, ans = 0, left;
        for(int i = 0; i < m.size(); i++)
        {
            prev = 0;
            left = 0;
            for(int j = 0; j < m[0].size(); j++)
            {
                temp = dp[j];
                dp[j] = (m[i][j] == '1') ? min(left, min(dp[j], prev)) + 1: 0;
                prev = temp;
                left = dp[j];
                ans = max(ans, dp[j]);
            }
        }
        return ans*ans;
    }
};