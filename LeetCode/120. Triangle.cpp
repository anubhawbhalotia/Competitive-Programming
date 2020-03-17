class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0)
            return 0;
        vector<int> DP = triangle[(int)triangle.size() - 1];
        for(int i = (int)triangle.size() - 1; i > 0; i--)
        {
            for(int j = 0; j < (int)triangle[i].size() - 1; j++)
            {
                DP[j] = min(DP[j], DP[j+1]) + triangle[i-1][j];
            }
        }
        return DP[0];
    }
};