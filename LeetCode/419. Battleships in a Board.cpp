class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        for(int i=0; i!=board.size(); i++)
        {
            int j=0;
            while(j!=board[i].size())
            {
                if(board[i][j]=='.')
                {
                    j++;
                    continue;
                }
                if(j!=0)
                {
                    if(board[i][j-1]=='X')
                    {
                        j++;
                        continue;
                    }
                }
                if(i!=0)
                {
                    if(board[i-1][j]=='X')
                    {
                        j++;
                        continue;
                    }
                }
                ans++;
                j++;
            }
        }
        return ans;
    }
};