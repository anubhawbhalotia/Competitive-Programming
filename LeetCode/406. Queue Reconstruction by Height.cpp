#define mp make_pair
#define pb push_back
typedef pair <int, int> pairs;
typedef set<pairs> spll;
typedef list<pair <int, int> > lpii;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {   
        vector<vector<int>> ans;
        if(people.size() == 0)
            return ans;
        spll s;
        lpii l;
        set <int> d[people.size() + 1];
        for(int i = 0; i != people.size(); i++)
            s.insert(mp(people[i][0], people[i][1]));
        spll :: reverse_iterator it = s.rbegin();
        int last = s.rbegin() -> first;
        int x = 0;
        while(1)
        {
            if(it != s.rend() && it->first == last)
            {
                d[x].insert(it->second);
                it++;
                continue;
            } 
            for(set <int> :: iterator i = d[x].begin(); i != d[x].end(); i++) 
            {
                lpii :: iterator j = l.begin();
                int temp = *i;
                while(temp--)
                    j++;
                l.insert(j, mp(last, *i));
            }
            x++;
            if(it != s.rend())
                last = it->first;
            else
                break;
        }
        
        for(lpii :: iterator it = l.begin(); it != l.end(); it++)
        {
            vector <int> temp;
            temp.pb(it->first);
            temp.pb(it->second);
            ans.pb(temp);
        }
        return ans;
    }
};