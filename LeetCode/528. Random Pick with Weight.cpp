class Solution {
public:
    set <pair<int, int>> s;
    int sum;
    
    Solution(vector<int>& w) {
        sum = 0;
        srand(time(NULL));
        for(int i = 0; i < w.size(); i++)
        {
            sum += w[i];
            s.insert(make_pair(sum, i));
        }
    } 
    int pickIndex() {
        int r = (rand() % sum);
        return s.upper_bound(make_pair(r, 10000))->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */