class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        map <char,char> m;
        m['('] = ')';
        m['{'] = '}';
        m['['] = ']';
        for(int i=0;i!=s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
               st.push(s[i]);
            else
            {
                if(st.empty())
                    return false;
                if(m[st.top()]!=s[i])
                    return false;
                st.pop();
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};