class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<int> a(n, 0);
        for(int i = 2; i < n; i++) {
            if (a[i] == 0) {
                ans++;
                for (int j = i + i; j < n; j += i) {
                    a[j] = 1;
                }
            }
        }
        return ans;
    }
};