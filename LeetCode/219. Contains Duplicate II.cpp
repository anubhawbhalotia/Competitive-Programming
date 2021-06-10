class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> m;
        for (int i = 0; i < min(k + 1, (int)nums.size()); i++) {
            if (m.find(nums[i]) != m.end()) {
                return true;
            }
            m.insert(nums[i]);
        }
        for (int i = k + 1; i < nums.size(); i++) {
            m.erase(nums[i - k - 1]);
            if (m.find(nums[i]) != m.end()) {
                return true;
            }
            m.insert(nums[i]);
        }
        return false;
    }
};