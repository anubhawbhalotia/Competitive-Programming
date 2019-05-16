class Solution {
public:
    string rec(string s, int start, int* end)
    {
        int k = 0, c = 0;
        string ans;
        while(start != s.length())
        {
            if(s[start] >= '0' && s[start] <= '9')
                k = k*10 + (s[start] - '0');
            else if(s[start] == '[')
            {
                string temp = rec(s, start + 1, end);
                start = (*end) - 1;
                for(int i = 0; i != k; i++)
                    ans += temp;
                k = 0;
            }
            else if(s[start] == ']')
                c--;
            else
                ans += s[start];
            if(c<0)
            {
                *end = start + 1;
                return ans;
            }
            start++;
        }
        *end = start + 1;
        return ans;
    }
    string decodeString(string s) {
        int end;
        return rec(s, 0, &end);
    }
};