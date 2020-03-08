class Solution {
public:
    int confusingNumberII(int N) {
        int i = 1,ans = 0;
        unordered_map <int, int> s;
        vector <int> a = {0, 1, 6, 8, 9};
        vector <int> b = {0, 1, 9, 8, 6};
        for(int i = 0; i < a.size(); i++)
            s[a[i]] = b[i];
        int j, k, t;
        while(i <= N)
        {
            j = 1, k = i, t = 0;
            while(k)
            {
                if(s.find(k % 10) != s.end())
                {
                    if(t > 214748363)
                        t = N+1;
                    else
                        t = (t*10) + s[k%10];
                    k /= 10;
                    j = (k == 0) ? j : j*10;
                }
                else
                {
                    break;
                }
            }
            if(!k)
            {
                if(t < i)
                {
                    ans++;
                    if(i % 10)
                        ans++;
                }
                else if(t > N)
                    ans++;
                i++;
            }
            else
            {
                i+=j;
            }
        }
        return ans;
    }
};