class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0)
            return "";
        int mv=0,len,d,start,end;
        start = 0;
        end = 0;
        for(int i=0;i!=s.length();i++)
        {
            d=0;
            len=1;
            while(i-d-1>=0 && i+d+1<s.length())
            {
                if(s[i-d-1] == s[i+d+1])
                {
                    d++;
                    len+=2;
                }
                else
                {
                    break;
                }
            }
            if(len>mv)
            {
                start = i-d;
                end = i+d;
                mv=len;
            }
        }
        for(int i=0;i<s.length()-1;i++)
        {
            int st=i;
            int en = i+1;
            if(s[st]!=s[en])
                continue;
            int flag=0;
            // cout<<st<<" "<<en<<endl;
            while(st-1>=0 && en+1<s.length())
            {
                // cout<<"while "<<st<<" "<<en<<endl;
                if(s[st-1] == s[en+1])
                {
                    st--;
                    en++;
                }
                else
                    break;
            }
            if(en-st+1>mv)
            {
                mv = en-st+1;
                start = st;
                end = en;
            }
        }
        cout<<mv<<endl;
        return s.substr(start,end-start+1);
    }
};