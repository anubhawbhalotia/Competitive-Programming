class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
            return 0;
        vector <int> DP(n + 1, 0);
        DP[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            DP[i] = 2*DP[i-1];
            for(int j = 1; j < i - 1; j++)
            {
                DP[i] += DP[j] * DP[i-1-j];
            }
        }
        return DP[n];
    }
};