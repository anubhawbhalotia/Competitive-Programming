class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(!(int)grid.size())
            return 0;
        vector<int> DP((int)grid[0].size(), INT_MAX);
        DP[0] = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            DP[0] += grid[i][0];
            for(int j = 1; j < grid[0].size(); j++)
            {
                DP[j] = min(DP[j-1], DP[j]) + grid[i][j];
            }
        }
        return DP[grid[0].size() - 1];
    }
};