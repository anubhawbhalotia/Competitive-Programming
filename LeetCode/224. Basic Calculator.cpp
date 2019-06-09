class Solution {
public:
    int x;
    string str;
    int solve()
    {
        int ans = 0, temp = 0, b = 1;
        while(x < str.length())
        {
            if(str[x] == ')')
            {
                ans += b*temp;
                return ans;
            }
            if(str[x] == '(')
            {
                x++;
                temp = solve();  
            }
            else if(str[x] == '+' || str[x] == '-')
            {
                ans += b*temp;
                temp = 0;
                b = (str[x] == '+') ? 1 : -1;
            }
            else if(str[x] >= '0' && str[x] <= '9')
                temp = (temp*10) + (str[x] - 48);
            x++;
        }
        ans += b*temp;
        return ans;
    }
    int calculate(string s) {
        str = s;
        x = 0;
        return solve();
    }
};