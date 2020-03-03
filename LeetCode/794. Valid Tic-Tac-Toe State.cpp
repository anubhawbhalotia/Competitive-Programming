class Solution {
public:
    vector <int> count(vector<string>&b)
    {
        vector <int> c(2, 0);
        for(auto i : b)
        {
            for(auto j : i)
            {
                if(j == 'X')
                    c[0]++;
                else if(j == 'O')
                    c[1]++;
            }       
        }
        return c;
    }
    int getWinner(vector <string> b)
    {
        map <char, int> m;
        m['X'] = 0;
        m['O'] = 1;
        set<int> s;
        for(auto i : {0, 1, 2})
        {
            if(b[0][i] == b[1][i] && b[1][i] == b[2][i])
            {
                if(b[0][i] != ' ')
                    s.insert(m[b[0][i]]);
            }
            if(b[i][0] == b[i][1] && b[i][1] == b[i][2])
            {
                if(b[i][0] != ' ')
                    s.insert(m[b[i][0]]);
            }
        }
        if(b[0][0] == b[1][1] && b[1][1] == b[2][2])
        {
            if(b[0][0] != ' ')
                s.insert(m[b[0][0]]);
        }
        if(b[2][0] == b[1][1] && b[1][1] == b[0][2])
        {
            if(b[2][0] != ' ')
                s.insert(m[b[2][0]]);
        }
        if(s.empty())
            s.insert(-1);
        if(s.size() > 1)
            return -2;
        else
            return *s.begin();
                         
    }
    bool validTicTacToe(vector<string>& b) {
        vector <int> c = count(b);
        if(c[0] != c[1] && c[0] != (c[1] + 1))
            return false;
        int winner = getWinner(b);
        cout<<c[0]<<" "<<c[1]<<" "<<winner<<endl;
        if(winner == -2)
            return false;
        if(c[0] == c[1] + 1 && winner != 1)
            return true;
        if(c[0] == c[1] && winner != 0)
            return true;
        return false;
    }
};