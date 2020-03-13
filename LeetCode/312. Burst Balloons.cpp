class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<int> a(n, 0);
        vector<vector<int>> DP(n, vector<int>(n, 0));
        a[0] = 1;
        a[n - 1] = 1;
        for(int i = 0; i < n - 2; i++)
            a[i+1] = nums[i];
        for(int i = 2; i < n; i++)
        {
            for(int j = 0; j < n - i; j++)
            {
                for(int k = j + 1; k < j + i; k++)
                {
                    DP[j][j+i] = max(DP[j][j+i], DP[j][k] + DP[k][j+i] + a[j] * a[k] * a[j+i]);
                }
            }
        }
        return DP[0][n-1];
    }
};