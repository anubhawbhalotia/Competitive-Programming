// Time : O(n)
// Space : O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int s = 0, e = nums.size() - 1;
        while(s <= e) {
            while(s <= e && nums[s] == val) {
                swap(nums[s], nums[e]);
                e--;
            }
            if (nums[s] != val) {
                s++;
            }
        }
        return s;
    }
};