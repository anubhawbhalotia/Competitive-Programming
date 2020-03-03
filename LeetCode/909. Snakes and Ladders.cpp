class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& b) {
        int n = b.size(), p = n*n, z = 1;
        if(p == 1)
            return 0;
        unordered_map <int,int> m;
        bool par = 1;
        for(int i = (n - 1); i >= 0; i--)
        {
            if(par)
                for(int j = 0; j < n; j++, z++)
                    m[z] = (b[i][j] != -1) ? b[i][j] : z;
            else
                for(int j = n-1; j >=0; j--, z++)
                    m[z] = (b[i][j] != -1) ? b[i][j] : z;
            par = !par;
        }
        vector <bool> flag(p+1, false);
        queue <int> q;
        q.push(1);
        flag[q.back()] = true;
        z = 1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int temp = q.front();
                q.pop();
                for(auto i : {6, 5, 4, 3, 2, 1})
                {
                    if(m[temp + i] <= p)
                    {
                        if(!flag[m[temp+i]])
                        {
                            if(m[temp+i] == p)
                                return z;
                            q.push(m[temp+i]);
                            flag[q.back()] = true;
                        }
                    }
                }
            }
            z++;
        }
        return -1;
    }
};