class Solution {
public:
    int shortestWay(string source, string target) {
        vector <int> maxLength(1001, 0), temp(1001, -1);
        vector <set<int>> v(26);
        set <int> :: iterator it;
        int sl = source.length(), tl = target.length();
        for(int i = 0; i != sl; i++)
        {
            v[source[i] - 'a'].insert(i);
        }
        for(int k = 0; k != tl; k++)
        {
            int i = k, j = -1;
            while(i != tl)
            {
                it = v[target[i] - 'a'].upper_bound(j);
                if(it == v[target[i] - 'a'].end())
                {
                    break;
                }
                j = *it;
                if(j == temp[i])
                {
                    i = maxLength[k - 1] + 1;
                    break;
                }
                temp[i++] = j;
            }
            maxLength[k] = i - 1;
            if(i == k)
                return -1;
        }
        int flag = maxLength[0], ans = 1, i = 1, M = maxLength[0];
        while(i != tl)
        {
            M = max(M, maxLength[i]);
            if(i > flag)
            {
                flag = M;
                ans++;
            }
            i++;
        }
        return ans;
    }
};