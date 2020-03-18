class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <int> DP(n, 1);
        for(int i = 0; i < m - 1; i++)
        {
            for(int j = 1; j < n; j++)
            {
                DP[j] = DP[j-1] + DP[j];
            }
        }
        return DP[n-1];
    }
};