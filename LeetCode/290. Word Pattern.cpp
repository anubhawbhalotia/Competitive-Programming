class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int x = 0, y = 0;
        map<char, string> a;
        set<string> b;
        while(y < pattern.length() && x < s.length()) {
            string temp = "";
            while(x < s.length() && s[x] != ' ') {
                temp += s[x++];
            }
            if (a.find(pattern[y]) == a.end()) {
                if (b.find(temp) == b.end()) {
                    a[pattern[y]] = temp;
                    b.insert(temp);
                } else {
                    return false;
                }
            } else {
                if (a[pattern[y]] != temp) {
                    return false;
                }
            }
            x++;
            y++;
        }
        return (x >= s.length() && y >= pattern.length());
    }
};