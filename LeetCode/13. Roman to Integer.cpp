class Solution {
public:
    int romanToInt(string s) {
        map <char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int i=0, ans=0;
        while(i!=s.length())
        {
            if(i!=s.length()-1)
            {
                if(s[i]=='I')
                {
                    if(s[i+1]=='V')
                    {
                        ans+=4;
                        i+=2;
                    }
                    else if(s[i+1]=='X')
                    {
                        ans+=9;
                        i+=2;
                    }
                    else
                    {
                        ans+=m[s[i]];
                        i++;
                    }
                }
                else if(s[i]=='X')
                {
                    if(s[i+1]=='L')
                    {
                        ans+=40;
                        i+=2;
                    }
                    else if(s[i+1]=='C')
                    {
                        ans+=90;
                        i+=2;
                    }
                    else
                    {
                        ans+=m[s[i]];
                        i++;
                    }
                }
                else if(s[i]=='C')
                {
                    if(s[i+1]=='D')
                    {
                        ans+=400;
                        i+=2;
                    }
                    else if(s[i+1]=='M')
                    {
                        ans+=900;
                        i+=2;
                    }
                    else
                    {
                        ans+=m[s[i]];
                        i++;
                    }
                }
                else
                {
                    ans+=m[s[i]];
                    i++;
                }
            }
            else
            {
                ans+=m[s[i]];
                i++;
            }
        }
        return ans;
    }
};