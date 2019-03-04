class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque < int>  d,e;
        vector <int> ans;
        if(nums.size()==0)
            return ans;
        for(int i = 0; i!=k; i++)
        {
            if(d.empty())
            {
                d.push_back(nums[i]);
                e.push_back(i);
                continue;
            }
            while(!d.empty() && d.back() <= nums[i])
            {
                d.pop_back();
                e.pop_back();
            }
            d.push_back(nums[i]);
            e.push_back(i);                  
        }
        ans.push_back(d.front());
        for(int i = k; i!=nums.size(); i++)
        {
            while(!d.empty() && d.back() <= nums[i])
            {
                d.pop_back();
                e.pop_back();
            }
            d.push_back(nums[i]);
            e.push_back(i);
            while(!d.empty() && e.front() <= i-k)
            {
                d.pop_front();
                e.pop_front();
            }
            ans.push_back(d.front());
        }       
        return ans;
    }
};