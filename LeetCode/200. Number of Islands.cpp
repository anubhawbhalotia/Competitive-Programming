class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        int ans=0;
        for(int i=0; i!=grid.size(); i++)
        {
            for(int j=0;j!=grid[i].size();j++)
            {
                if(grid[i][j]!='1')
                    continue;
                queue <pair <int, int> >  q;
                ans++;
                q.push(make_pair(i,j));
                grid[i][j]='2';
                while(!q.empty())
                {
                    pair <int,  int> p = q.front();
                    q.pop();
                    for(int k=0;k<4;k++)
                    {
                        int tempR=p.first+r[k];
                        int tempC=p.second+c[k];
                        if(tempR<0 || tempR >=grid.size())
                            continue;
                        if(tempC<0 || tempC>=grid[0].size())
                            continue;
                        if(grid[tempR][tempC]=='1')
                        {
                            grid[tempR][tempC]='2';
                            q.push(make_pair(tempR,tempC));
                        }
                    }
                }
            }
        }
        return ans;
    }
};