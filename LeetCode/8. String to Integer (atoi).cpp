class Solution {
public:
    int myAtoi(string str) {
        int i=0,s=1;
        while(i!=str.length() && str[i]==' ')
            i++;
        if(str[i]=='+')
        {
            s=1;
            i++;
        }
        else if(str[i]=='-') 
        {
            s=-1;
            i++;
        }
        long ans=0;
        cout<<s<<endl;
        while(i!=str.length() && str[i]>='0' && str[i]<='9')
        {
            ans = (ans>=0)?(ans*10)+str[i]-48 : (ans*10-str[i]+48);
            if(ans!=0)
            {
                ans*=s;
                s=1;
            }
            // cout<<ans<<" "<<str[i]-48<<endl;
            i++;
            if(ans>INT_MAX)
                return INT_MAX;
            if(ans<INT_MIN)
                return INT_MIN;
        }
        return ans;
            
        
    }
};