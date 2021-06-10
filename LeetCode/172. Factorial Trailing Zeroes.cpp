class Solution {
public:
    int trailingZeroes(int n) {
        int mul = 5, ans = 0;
        while (mul <= n) {
            ans += (n / mul);
            mul *= 5;
        }
        return ans;
    }
};