class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> a(300, -1), b(300, -1);
        for (int i = 0; i < s.length(); i++) {
            if(a[s[i]] == -1) {
                if (b[t[i]] == 1) {
                    return false;
                }
                a[s[i]] = t[i];
                b[t[i]] = 1;
            } else {
                if (a[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};