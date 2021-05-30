// Time : O(max(m, n))
// Space  : O(max(m, n))
class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        int x = a.length() - 1;
        int y = b.length() - 1;
        string z;
        int p = 0;
        while (p <= max(x, y)) {
            if (x >= 0) {
                c += (a[x--] & 1);
            }
            if (y >= 0) {
                c += (b[y--] & 1);
            }
            z += (c & 1) + '0';
            c = (c / 2) & 1;
        }
        if (c == 1) {
            z += '1';
        }
        reverse(z.begin(), z.end());
        return z;
    }
};