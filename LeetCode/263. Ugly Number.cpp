class Solution {
public:
    bool isUgly(int n) {
        if (n == 0) {
            return false;
        }
        vector<int> a = {2, 3, 5};
        for(auto i : a) {
            while(n % i == 0) {
                n /= i;
            }
        }
        return n == 1;
    }
};