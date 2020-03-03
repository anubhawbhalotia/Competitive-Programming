class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& b) {
        int n = b.size(), p = n*n;
        //boustrophedonically mapping
        int z = 1;
        unordered_map <int,int> m;
        bool par = 1;
        for(int i = (n - 1); i >= 0; i--)
        {
            if(par)
            {
                for(int j = 0; j < n; j++)
                {
                    m[z++] = b[i][j];
                }
            }
            else
            {
                for(int j = n-1; j >=0; j--)
                {
                    m[z++] = b[i][j];
                }
            }
            par = !par;
        }
        vector <bool> flag(p+1, false);
        queue <int> q;
        q.push(1);
        flag[1] = true;
        // int x[] = {1, 2, 3, 4, 5, 6};
        int x[] = {6, 5, 4, 3, 2, 1};
        int dis = 1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int temp = q.front();
                q.pop();
                for(auto i : x)
                {
                    if(temp + i <= p)
                    {
                        if(m[temp+i] != -1)
                        {
                            if(!flag[m[temp+i]])
                            {
                                flag[m[temp+i]] = true;
                                q.push(m[temp+i]);
                            }
                        }
                        else
                        {
                            if(!flag[temp+i])
                            {
                                flag[temp+i] = true;
                                q.push(temp+i);
                            }
                        }
                    }
                    if(q.empty() == false && q.back() == p)
                    {
                        return dis;
                    }
                }
            }
            dis++;
        }
        return -1;
    }
};