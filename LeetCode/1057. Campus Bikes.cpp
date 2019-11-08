class node
{
public:
    int distance;
    int workerIndex;
    int bikeIndex;
    node(int d, int wi, int bi)
    {
    	distance = d;
    	workerIndex = wi;
    	bikeIndex = bi;
    }
    bool operator< (const struct node &right) const
    {
    	if(distance != right.distance)
    		return distance < right.distance;
    	if(workerIndex != right.workerIndex)
    		return workerIndex < right.workerIndex;
    	if(bikeIndex != right.bikeIndex)
    		return bikeIndex < right.bikeIndex;
    	return false;
    }

};
class Solution {
public:
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        set <node> s;
        unordered_set <int> w, b;
        for(int i = 0; i != workers.size(); i++)
        {   
            for(int j = 0; j != bikes.size(); j++)
            {
                node temp(abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]), i, j);
                s.insert(temp);
            }
        }
        vector <int> ans(workers.size());
        for(set <node> :: iterator it = s.begin(); it != s.end(); it++)
        {
            if(w.find(it->workerIndex) != w.end() || b.find(it->bikeIndex) != b.end())
                continue;
            ans[it->workerIndex] = it->bikeIndex;
            w.insert(it->workerIndex);
            b.insert(it->bikeIndex);
        }
        return ans;
    }
};