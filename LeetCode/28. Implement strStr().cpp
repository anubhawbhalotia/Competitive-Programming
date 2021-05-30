class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) {
            return 0;
        }
        if (haystack.length() < needle.length()) {
            return -1;
        }
        for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {    
            int c = 0;
            while (c != needle.length()) {
                if (haystack[i + c] != needle[c]) {
                    break;
                }
                c++;
            }
            if (c == needle.length()) {
                return i;
            }
        }
        return -1;
    }
};