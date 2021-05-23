#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int y = x, n = 0, d;
        while(y != 0) {
            d = y % 10;
            if (n > INT_MAX / 10) {
                return false;
            }
            n *= 10;
            if (n > INT_MAX - d) {
                return false;
            }
            n += d;
            y /= 10;
        }
        return n == x;
    }
};