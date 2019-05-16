class Solution {
public:
    int numSquares(int n) {
        static vector <int> c {0};
        int ans, j;
        while(c.size() <= n)
        {
            ans = INT_MAX;
            j = 1;
            while(j*j <= c.size())
            {
                ans = min(ans, 1 + c[c.size() - j*j]);
                j++;
            }
            c.push_back(ans);
        }
        return c[n];
    }
};