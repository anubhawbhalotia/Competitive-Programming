class Solution {
public:
	void dp(vector<string> &arr, int level, int n, vector <int> &c_form, int curr, int temp, int &ans)
	{
		if(level == n)
		{
			ans = max(ans, temp);
            return;
		}
        int op = curr & c_form[level];
        int t = c_form[level] & (1<<26);
		if(op == 0 && t == 0)
		{
			dp(arr, level + 1, n, c_form, curr | c_form[level], temp + arr[level].length(), ans);
		}
		dp(arr, level + 1, n, c_form, curr, temp, ans);
	}
    int maxLength(vector<string>& arr) {
    	vector <int> c_form((int)arr.size(), 0); 
		for(int i = 0; i < arr.size(); i++)
		{
			for(auto j : arr[i])
			{
                int t = c_form[i] & (1<<(j-97));
                if(t)
                {
                    c_form[i] |= 1<<26;
                    break;
                }
				c_form[i] |= (1<<(j-97));
			}
		}
		int ans = 0;
		dp(arr, 0, arr.size(), c_form, 0, 0, ans);
		return ans;
    }
};