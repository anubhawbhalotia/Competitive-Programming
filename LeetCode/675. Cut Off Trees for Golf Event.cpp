class Solution {
public:
    typedef struct node
    {
        int val;
        int row;
        int col;
    }node;
    static  int comparator(const void *p, const void *q)  
    { 
        int l = ((node *)p)->val; 
        int r = ((node *)q)->val;  
        return (l - r); 
    } 
    int cutOffTree(vector<vector<int>>& forest) {
        node n[2501];
        int k = 0, row = forest.size(), col = forest[0].size();
        for(int i = 0; i != row; i++)
        {
            for(int j = 0; j != col; j++)
            {
                if(forest[i][j] > 1)
                {
                    n[k].val = forest[i][j];
                    n[k].row = i;
                    n[k].col = j;
                    k++;
                }
            }
        }
        qsort((void*)n,k,sizeof(n[0]),this->comparator);
        // for(int i = 0;i!=k ;i++)
        // {
        //     cout<<n[i].val<<" "<<n[i].row<<" "<<n[i].col<<endl;
        // }
        pair <int,int> curr = make_pair(0,0);
        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};
        long ans = 0;
        for(int i = 0; i!=k; i++)
        {
            int f[51][51] = {};
            if(forest[curr.first][curr.second] == 0)
            {
                // cout<<"exitpoint 1"<<endl;
                return -1;
            }
            if(forest[curr.first][curr.second] == n[i].val)
                continue;
            queue <pair < int, int> > q;
            q.push(curr);
            f[curr.first][curr.second] = 1;
            int level = 0;
            while(!q.empty())
            {
                int sz = q.size();
                int h;
                level++;
                for(h = 0; h < sz; h++)
                {
                    pair < int , int > t = q.front();
                    q.pop();
                    int j;
                    for(j = 0; j<4; j++)
                    {
                        int r = t.first + x[j];
                        int c = t.second + y[j];
                        // cout<<"r = "<<r<<" c = "<<c<<endl;
                        if(r<0 || r>=row || c<0 || c>=col || f[r][c]==1 || forest[r][c]==0)
                            continue;
                        if(forest[r][c] == n[i].val)
                        {
                            curr = make_pair(r,c);
                            ans += level;
                            q.push(make_pair(r,c));
                            // cout<<"ans found "<<ans<<endl;
                            break;
                        }
                        q.push(make_pair(r,c));
                        f[r][c] = 1;
                    }
                    if(j!=4)
                        break;
                }
                if(h!=sz)
                    break;
            }   
            if(q.empty())
                return -1;
        }
        return ans;
    }
};