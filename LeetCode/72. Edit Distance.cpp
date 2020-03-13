#define M 10000
class Solution {
public:
    vector<vector<int>> DP;
    int dp(int a, int b, string &w1, string &w2)
    {
        if(a == (int)w1.length() || b == (int)w2.length())
            return max((int)w2.length() - b, (int)w1.length() - a);
        if(DP[a][b] != -1)
            return DP[a][b];
        if(w1[a] == w2[b])
        {
            DP[a][b] = dp(a + 1, b + 1, w1, w2);
        }
        else
        {
            DP[a][b] = min(dp(a + 1, b + 1, w1, w2), dp(a, b + 1, w1, w2)) + 1;
            DP[a][b] = min(DP[a][b], dp(a + 1, b, w1, w2) + 1);
        }
        return DP[a][b];
    }
    int minDistance(string w1, string w2) {
        DP.resize((int)w1.size(), vector<int>((int)w2.size(), -1));
        return dp(0, 0, w1, w2);
    }
};