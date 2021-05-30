class Solution {
public:
    int lengthOfLastWord(string s) {
        int y = s.length() - 1;
        int c = 0;
        while(y >= 0) {
            if (s[y] != ' ') {
                c++;
            } else if (c != 0) {
                return c;
            }
            y--;            
        }
        return c;
    }
};