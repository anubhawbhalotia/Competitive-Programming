class Solution {
public:
    bool solve(vector<int> &a, int &m, int &c, int x, int y, int s)
    {
        if(y == 0)
        {
            return (!s) ? 1 : 0;
        }
        if(x == m + 1)
            return 0;
        if(a[x] != 0 && solve(a, m, c, x + 1, y - 1, s - a[x]))
        {
            a[x] = 0;
            c--;
            return 1;
        }
        return solve(a, m, c, x + 1, y, s);
    }
    int minTransfers(vector<vector<int>>& t) {
        vector<int> a(1000, 0);
        int m = 0, y = 2, ans = 0;
        for(auto i : t)
        {
            a[i[0]] -= i[2];
            a[i[1]] += i[2];
            m = max(m, max(i[0], i[1]));
        }
        int c = m + 1;
        for(int i = 0; i <= m; i++)
        {
            if(a[i] == 0)
                c--;
        }
        while(c)
        {
            if(!solve(a, m, c, 0, y, 0))
                y++; 
            else
                ans += (y - 1);
        }
        return ans;
    }
};