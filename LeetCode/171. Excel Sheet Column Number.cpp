class Solution {
public:
    int titleToNumber(string s) {
        long ans=0;
     for(int i=s.length()-1; i>=0; i--)
     {
         ans+=pow(26,s.length()-i-1)*(s[i]-64);
     }
        return ans;
    }
};