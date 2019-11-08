class Solution {
public:
    int shortestWay(string source, string target) {
        int ans = 0;
        for(int i = 0; i != target.length();)
        {
            int temp = i;
            for(int j = 0; j != source.length(); j++)
            {
                if(target[i] == source[j])
                {
                    i++;
                }
                if(i == target.length())
                {
                    break;
                }
            }
            if(i == temp)
                return -1;
            else
                ans++;
        }
        return ans;
        
    }
};