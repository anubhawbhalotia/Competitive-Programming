class Solution {
    vector<vector<vector<int>>> DP;
    int a, b, c;
public:
    bool dp(int x, int y, int z, string &s1, string &s2, string &s3)
    {
        // cout<<x<<" "<<y<<" "<<z<<endl;
        if(z == c)
            return 1;
        if(DP[x][y][z] != -1)
            return DP[x][y][z];
        DP[x][y][z] = 0;
        if(x < a && y < b && s1[x] != s3[z] && s2[y] != s3[z])
        {
            DP[x][y][z] = 0;
        }
        if(x < a && s1[x] == s3[z])
        {
            DP[x][y][z] = dp(x + 1, y, z + 1, s1, s2, s3);
        }
        if(y < b && s2[y] == s3[z])
        {
            DP[x][y][z] = max(DP[x][y][z], (int)dp(x, y + 1, z + 1, s1, s2, s3));
        }
        return DP[x][y][z];
    }
    bool isInterleave(string s1, string s2, string s3) {
        a = s1.length();
        b = s2.length();
        c = s3.length();
        if(a + b != c)
            return 0;
        DP.resize(a + 2, vector<vector<int>>(b + 2,vector<int>(c + 2, -1)));
        return dp(0, 0, 0, s1, s2, s3);
    }
};