class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector <int> ans;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
        if(carry)
            ans.push_back(carry);
        for(int i = 0; i != digits.size(); i++)
            ans.push_back(digits[i]);
        return ans;
    }
};