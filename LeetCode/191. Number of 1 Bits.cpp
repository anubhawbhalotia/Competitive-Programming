// Time O(1)
// Space O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n) {
            ans += (n % 2);
            n /= 2;
        }
        return ans;
    }
};