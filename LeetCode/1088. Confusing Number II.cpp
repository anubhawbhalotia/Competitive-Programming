#include<bits/stdc++.h>
class Solution {
public:
    int isValid(int x, unordered_map <int, int> &m)
    {
        int temp = x, t = 0;
        while(x)
        {
            if(t > 214748363)
                return 1;
            t = t*10 + (m[x%10]);
            x /= 10;
        }
        if(t != temp)
            return 1;
        return 0;
    }
    void dp(int dig, int &N, vector <int> &a, vector <int> &b, int x, int &ans,unordered_map<int, int> &m)
    {
        if(x > N)
            return;
        ans += (isValid(x, m));
        for(int i = (dig == 1) ? 1 : 0; i < 5; i++)
        {
            if(x < 214748363)
                dp(dig+1, N, a, b, (x*10) + a[i], ans, m);
        }
    }
    int confusingNumberII(int N) {
        unordered_map <int, int> m;
        vector <int> a = {0, 1, 6, 8, 9};
        vector <int> b = {0, 1, 9, 8, 6};
        for(int i = 0; i < a.size(); i++)
            m[a[i]] = b[i];
        int ans = 0;
        dp(1, N, a, b, 0, ans, m);
        return ans;
    }
};