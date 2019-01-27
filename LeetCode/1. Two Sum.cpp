class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set <pair <int, int> > s;
        for(int i=0;i!=nums.size();i++)
        {
            s.insert(make_pair(nums[i],i));
        }
        vector <int> v;
        for(set <pair <int, int> > ::iterator i = s.begin();
           i!=s.end(); i++)
        {
            // cout<<i->first<<" "<<i->second<<endl;
            set <pair <int, int> > :: iterator  it=
              s.upper_bound(make_pair((target - (i->first)), i->second));
            if(it==s.end())
                continue;
            // cout<<it->first<<" "<<it->second<<endl;
            if(it->first==target-(i->first))
            {
                v.push_back(i->second);
                v.push_back(it->second);
                break;
            }
        }
        return v;
    }
};