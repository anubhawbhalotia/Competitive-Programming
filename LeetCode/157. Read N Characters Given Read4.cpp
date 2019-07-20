// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int c = 0, temp = 4;
        while(n >= 4 && temp == 4)
        {
            temp = read4(buf + c);
            n -= temp;
            c += temp;
        }
        if(n > 0 && temp == 4)
        {
            char* t = new char[4];
            temp = read4(t);
            int x = 0;
            while(n > 0 && temp > 0)
            {
                *(buf + c++) = *(t + x++);
                n--;
                temp--;
            }
        }
        *(buf + c++) = '\0';
        return c;
    }
};