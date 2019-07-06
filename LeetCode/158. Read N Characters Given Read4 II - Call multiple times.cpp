// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int c, p;
    Solution()
    {
        c = 0;
        p = 0;
    }
    char s[1000];
    int read(char *buf, int n) {
        int r;
        while(1)
        {
            r = read4(s + c);
            if(!r)
                break;
            c += r;
        }
        int d = 0;
        while(p < c && d < n)
        {
            *(buf + d) = *(s + p);
            p++;
            d++;
        }
        return d;
    }
};