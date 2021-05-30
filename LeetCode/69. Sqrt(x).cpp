// Time : O(log n)
// Space : O(1)
class Solution {
public:
    int mySqrt(int x) {
        long long s = 0, e = x;
        while(s < e) {
            long long mid = (s + e + 1) / 2;
            if (mid * mid > x) {
                e = mid - 1;
            } else {
                s = mid;
            }
        }
        return s;
    }
};