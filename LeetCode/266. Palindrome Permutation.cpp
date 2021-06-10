class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> a(300, 0);
        bool found = false;
        for(auto i : s) {
            a[i]++;
        }
        for(auto i : a) {
            if (i % 2) {
                if (found) {
                    return false;
                }
                found = true;
            }
        }
        return true;
    }
};