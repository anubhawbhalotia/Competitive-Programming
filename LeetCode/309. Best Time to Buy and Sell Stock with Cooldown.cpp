class Solution {
public:
    int maxProfit(vector<int>& p) {
        if(p.empty())
            return 0;
        vector <int> DP((int)p.size(), 0);
        int M = -p[0];
        for(int i = 1; i < (int)p.size(); i++)
        {
            DP[i] = max(DP[i - 1], p[i] + M);
            M = max(M, (i >= 2) ? DP[i - 2] - p[i] : -p[i]);
        }
        return DP.back();
    }
};