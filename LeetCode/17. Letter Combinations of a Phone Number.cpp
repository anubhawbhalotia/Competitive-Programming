class Solution {
public:
    string a[10];
    vector <string> ans;
    void rec(string digits, int level, string temp)
    {
        // cout<<level<<" "<<digits.length()<<endl;
        if(level == digits.length())
        {
            ans.push_back(temp);
            return ;
        }
        // cout<<a[digits[level]-48]<<endl;
        for(int i = 0; i != a[digits[level]-48].length(); i++)
            rec(digits, level+1, temp+a[digits[level]-48][i]);
    }
    vector<string> letterCombinations(string digits, int level = 0) {
        if(digits == "")
            return ans;
        a[0] = "";
        a[1] = "";
        a[2] = "abc";
        a[3] = "def";
        a[4] = "ghi";
        a[5] = "jkl";
        a[6] = "mno";
        a[7] = "pqrs";
        a[8] = "tuv";
        a[9] = "wxyz";
        rec(digits, 0, "");
        return ans;
    }
};