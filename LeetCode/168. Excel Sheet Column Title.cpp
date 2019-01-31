class Solution {
public:
    string convertToTitle(int n) {
        string ans="";
        n--;
        while(1)
        {
            char temp;
            temp = 'A'+((n)%26);
            ans =temp +ans;
            n=n/26;
            if(n==0)
                break;
            n--;
        }
       return ans;
    }
};