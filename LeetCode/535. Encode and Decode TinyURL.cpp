class Solution {
public:

    // Encodes a URL to a shortened URL.
    map <string, string> m;
    map <string, string> u;
    long x;
    Solution()
    {
        x = 0;
    }
    string itoa(long x)
    {
        string s;
        while(x != 0)
        {
            s += (x%10) + 48;
            x = x/10;
        }
        // reverse(s.begin(), s.end());
        return s;
    }
    string encode(string longUrl) {
        m[longUrl] = itoa(x);
        u[itoa(x)] = longUrl;
        x++;
        return m[longUrl];
    }
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return u[shortUrl]; 
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));