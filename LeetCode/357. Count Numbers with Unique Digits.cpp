class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1, a, c;
        for(int i = 1; i <= n; i++)
        {
            a = 9;
            c = 9;
            for(int j = 2; j <= i; j++)
                a *= c--;
            ans += a;
        }
        return ans;
    }
};