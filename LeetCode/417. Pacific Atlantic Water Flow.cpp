#define pb push_back
#define pi pair <int, int>
#define mp make_pair
#define fi first
#define se second
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> p;
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        int r, c;
        pi temp;
        vector <int> z;
        for(int j = 0; j != n; j++)
            z.pb(0);
        for(int i = 0; i != m; i++)
            p.pb(z);
        for(int i = 0; i != m; i++)
        {
            if((p[i][0] & 1) != 1)
            {
                stack <pi> s;
                s.push(mp(i, 0));
                p[i][0] |= 1;
                while(!s.empty())
                {
                    temp = s.top();
                    s.pop();
                    for(int j = 0; j != 4; j++)
                    {
                        r = temp.fi + row[j];
                        c = temp.se + col[j];
                        if(r >= 0 && r <= m - 1 && c >= 0 && c <= n - 1)
                        {
                            if((p[r][c] & 1) == 0 && matrix[r][c] >= matrix[temp.fi][temp.se])
                            {
                                s.push(mp(r, c));
                                p[r][c] |= 1;
                            }
                        }
                    }
                }
            }
            if((p[i][n - 1] & 2) != 1)
            {
                stack <pi> s;
                s.push(mp(i, n - 1));
                p[i][n - 1] |= 2;
                while(!s.empty())
                {
                    temp = s.top();
                    s.pop();
                    for(int j = 0; j != 4; j++)
                    {
                        r = temp.fi + row[j];
                        c = temp.se + col[j];
                        if(r >= 0 && r <= m - 1 && c >= 0 && c <= n - 1)
                        {
                            if((p[r][c] & 2) == 0 && matrix[r][c] >= matrix[temp.fi][temp.se])
                            {
                                s.push(mp(r, c));
                                p[r][c] |= 2;
                            }
                        }
                    }
                }
            }
        }
        for(int i = 0; i != n; i++)
        {
            if((p[0][i] & 1) != 1)
            {
                stack <pi> s;
                s.push(mp(0, i));
                p[0][i] |= 1;
                while(!s.empty())
                {
                    temp = s.top();
                    s.pop();
                    for(int j = 0; j != 4; j++)
                    {
                        r = temp.fi + row[j];
                        c = temp.se + col[j];
                        if(r >= 0 && r <= m - 1 && c >= 0 && c <= n - 1)
                        {
                            if((p[r][c] & 1) == 0 && matrix[r][c] >= matrix[temp.fi][temp.se])
                            {
                                s.push(mp(r, c));
                                p[r][c] |= 1;
                            }
                        }
                    }
                }
            }
            if((p[m - 1][i] & 2) != 1)
            {
                stack <pi> s;
                s.push(mp(m - 1, i));
                p[m - 1][i] |= 2;
                while(!s.empty())
                {
                    temp = s.top();
                    s.pop();
                    for(int j = 0; j != 4; j++)
                    {
                        r = temp.fi + row[j];
                        c = temp.se + col[j];
                        if(r >= 0 && r <= m - 1 && c >= 0 && c <= n - 1)
                        {
                            if((p[r][c] & 2) == 0 && matrix[r][c] >= matrix[temp.fi][temp.se])
                            {
                                s.push(mp(r, c));
                                p[r][c] |= 2;
                            }
                        }
                    }
                }
            }
        }
        vector <vector <int> > ans;
        for(int i = 0; i != m; i++)
        {
            for(int j = 0; j != n; j++)
            {
                vector <int> t;
                if(p[i][j] == 3)
                {
                    t.pb(i);
                    t.pb(j);
                    ans.pb(t);
                }
            }
        }
        return ans;        
    }
};