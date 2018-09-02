class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        set <long> s;
        long long c=0;
        int l=A.size();
        int t=l-1;
        int f=0;
        long o[500001];
        for(vector <int> :: reverse_iterator i=A.rbegin();i!=A.rend();i++)
        {
            f=f|*i;
            o[t]=f;
            t--;
        }
        long ind=0;
        for(vector <int> :: iterator i=A.begin();i!=A.end();i++)
        {
            long long ans=0;
            for(vector <int> :: iterator j=i;j!=A.end();j++)
            {
                ans=ans|*j;
                if(s.begin()==s.end())
                {
                    c++;
                    s.insert(ans);
                }
                else if(*(s.lower_bound(ans))!=ans)
                {
                    c++;
                    s.insert(ans);
                }
                if(ans==o[ind]) 
                    break;
            }
            ind++;  
        }
        return c;
    }
};