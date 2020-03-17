class Solution {
    vector<vector<int>> DP;
    vector<vector<int>> max_range;
public:
    void preprocessMax(vector<int> &arr)
    {
        for(int i = 0; i < (int)arr.size(); i++)
        {
            max_range[i][i] = arr[i];
            for(int j = i + 1; j < (int)arr.size(); j++)
            {
                max_range[i][j] = max(max_range[i][j-1], arr[j]);
            }
        }
    }
    int dp(vector<int> &arr, int l, int r)
    {
        if(DP[l][r] != INT_MAX)
            return DP[l][r];
        if(l == r)
            return 0;
        for(int i = l; i < r; i++)
        {
            int temp = dp(arr, l, i) + dp(arr, i + 1, r);
            temp +=  max_range[l][i]* max_range[i+1][r];
            DP[l][r] = min(DP[l][r], temp);
        }
        return DP[l][r];
    }
    int mctFromLeafValues(vector<int>& arr) {
        DP.resize(40, vector<int>(40, INT_MAX));
        max_range.resize(40, vector<int>(40, 0));
        preprocessMax(arr);
        return dp(arr, 0, arr.size() - 1);
    }
};