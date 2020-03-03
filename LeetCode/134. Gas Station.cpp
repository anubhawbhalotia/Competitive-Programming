class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector <int> cum;
        int tot_gas = 0, tot_cost = 0;
        multiset <int> s;
        for(int i = 0; i < gas.size(); i++)
        {
            tot_gas += gas[i];
            tot_cost += cost[i];
            cum.push_back(tot_gas-tot_cost);
            s.insert(cum[cum.size()-1]);
        }
        for(int i = 0; i < (int)gas.size() - 1; i++)
        {
            tot_gas += gas[i];
            tot_cost += cost[i];
            cum.push_back(tot_gas-tot_cost);
        }
        if(*s.begin() >= 0)
            return 0;
        for(int i = 0; i < (int)gas.size() - 1; i++)
        {
            s.erase(s.lower_bound(cum[i]));
            s.insert(cum[i + (int)gas.size()]);
            if(*s.begin() >= cum[i])
                return i + 1;
        }
        return -1;
    }
};