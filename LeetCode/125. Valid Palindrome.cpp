class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r) {
            while(!((s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= 'a' && s[l] <= 'z') || (s[l] >= '0' && s[l] <= '9'))) {
                l++;
                if (l >= r) {
                    return true;
                }
            }
            while(!((s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= 'a' && s[r] <= 'z') || (s[r] >= '0' && s[r] <= '9'))) {
                r--;
                if (l >= r) {
                    return true;
                }
            }
            // cout<<l<<" "<<r<<" "<<tolower(s[l])<<" "<<tolower(s[r])<<endl;
            if (l < r) {
                if (tolower(s[l]) != tolower(s[r])) {
                    // cout<<"false"<<endl;
                    return false;
                }
                l++;
                r--;
            }
        }
        return true;
    }
};