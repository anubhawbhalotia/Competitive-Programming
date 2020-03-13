class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(!n)
            return 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0, width;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                {
                    dp[i][j] = 1;
                    if(j)
                        dp[i][j] += dp[i][j-1];
                    width = dp[i][j];
                    for(int k = i; k >= 0; k--)
                    {
                        width = min(width, dp[k][j]);
                        if(!width)
                            break;
                        ans = max(ans, width * (i - k + 1));
                    }
                }
            }
        }
        return ans;
    }
};