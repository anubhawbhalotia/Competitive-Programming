// Time : O(1)
// Space : O(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int c = 0;
        while(n) {
            ans = (ans * 2) + (n % 2);
            n /= 2;
            c++;
        }
        while(c < 32) {
            ans = ans * 2;
            c++;
        }
        return ans;
    }
};