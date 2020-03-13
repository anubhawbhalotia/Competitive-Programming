class Solution {
public:
    vector<int> a;
    vector<vector<int>> DP;
    int dp(int l, int r)
    {
        if(l + 1 == r)
            DP[l][r] = 0;
        if(DP[l][r] != -1)
            return DP[l][r];
        for(int i = l + 1; i < r; i++)
        {
            int temp = a[l] * a[i] * a[r];
            temp += dp(l, i) + dp(i, r);
            DP[l][r] = max(DP[l][r], temp);
        }
        return DP[l][r];
    }
    int maxCoins(vector<int>& nums) {
        a.resize((int)nums.size() + 2, 0);
        DP.resize((int)a.size(), vector<int>((int)a.size(), -1));
        a[0] = 1;
        a[(int)a.size() - 1] = 1;
        for(int i = 0; i < (int)nums.size(); i++)
            a[i+1] = nums[i];
        return dp(0, (int)a.size() - 1);
    }
};