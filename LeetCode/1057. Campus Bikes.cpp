class Solution {
public:
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector <vector<pair<int, int>>> s(2001);
        vector <int> w(1001, 0), b(1001, 0), ans(workers.size());
        for(int i = 0; i != workers.size(); i++)
        {   
            for(int j = 0; j != bikes.size(); j++)
            {
                s[abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1])].push_back(make_pair(i, j));
            }
        }
        int count(0);
        for(int i = 0; i < 2001; i++)
        {
            for(int j = 0; j != s[i].size(); j++)
            {
                if(w[s[i][j].first] == 1 || b[s[i][j].second] == 1)
                {
                    continue;
                }
                ans[s[i][j].first] = s[i][j].second;
                w[s[i][j].first] = 1;
                b[s[i][j].second] = 1;
                count++;
                if(count == (int)workers.size())
                    return ans;
            }
            if(count == (int)workers.size())
            { 
                return ans;
            }
        }
        return ans;
    }
};