class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n, c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (c == 0) {
                n = nums[i];
                c++;
            } else {
                if (nums[i] != n) {
                    c--;
                } else {
                    c++;
                }
            }
        }
        return n;
    }
};