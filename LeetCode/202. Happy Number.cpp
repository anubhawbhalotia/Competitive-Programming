class Solution {
public:
    bool isHappy(int n) {
        int temp;
        while(n != 1) {
            temp = n;
            n = 0;
            while(temp) {
                n += ((temp % 10) * (temp % 10));
                temp /= 10;
            }
            if (n == 4) {
                return false;
            }
        }
        return true;
    }
};