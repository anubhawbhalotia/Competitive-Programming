class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        vector<vector<int>> h, v, ans;
        cout<<board.size()<<endl;
        if(board.size())
            cout<<board[0].size()<<endl;
        if(board[0].size() == 0)
            return ;
        for(int i = 0; i != board.size(); i++)
        {
            vector <int> s;
            s.push_back(0);
            if(board[0].size() > 1)
                s[0] = board[i][1];
            for(int j = 1; j < board[0].size() - 1; j++)
                s.push_back(board[i][j-1] + board[i][j+1]);
            if(board[0].size() > 1)
                s.push_back(board[i][board[0].size() - 2]);
            h.push_back(s);
        } 
        for(int i = 0; i != board.size(); i++)
        {
            vector <int> s;
            for(int j = 0; j != board[0].size(); j++)
            {
                s.push_back(0);
                if(i > 0)                
                    s[j] += board[i-1][j];
                if(i < board.size() - 1)
                    s[j] += board[i+1][j];
            }
            v.push_back(s);
        }
        for(int i = 0; i != board.size(); i++)
        {
            vector <int> s;
            for(int j = 0; j != board[0].size(); j++)
            {
                s.push_back(h[i][j]);
                if(i > 0)
                    s[j] += h[i-1][j];
                if(i < board.size() - 1)
                    s[j] += h[i+1][j];
                s[j] += v[i][j];
            }
            ans.push_back(s);
        }
        for(int i =0; i != board.size(); i++)
        {
            vector <int> s;
            for(int j = 0; j != board[0].size(); j++)
            {
                if(board[i][j] == 1)
                {
                    if(ans[i][j] < 2 || ans[i][j] > 3) 
                        board[i][j] = 0;
                    else
                        board[i][j] = 1;
                }
                else
                {
                    if(ans[i][j] == 3)
                        board[i][j] = 1;
                    else
                        board[i][j] = 0;
                }
            }
        }
    }
};