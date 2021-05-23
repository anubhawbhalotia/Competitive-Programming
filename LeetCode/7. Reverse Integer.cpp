#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        int d, n = 0, prev = 0;
        int s = (x / (abs(x)));
        x = abs(x);
        while(x != 0) {
            d = x % 10;
            if (n > INT_MAX / 10) {
                return 0;
            }
            n = n * 10;
            if (d > INT_MAX - n) {
                return 0;
            }
            n += d;
            if (prev > n) {
                return 0;
            }
            prev = n;
            x /= 10;
        }
        return n * s;
    }
};

int main() {
    
}