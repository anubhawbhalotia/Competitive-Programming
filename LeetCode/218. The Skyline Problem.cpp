class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        set <pair <int, pair < int,int > > > s;
        set <pair <int, int> > c;
        vector<pair<int, int>> ans;
        for(int i=0;i!=buildings.size();i++)
        {
            int l=buildings[i][0];
            int r=buildings[i][1];
            s.insert(make_pair(l,make_pair(1,i)));
            s.insert(make_pair(r,make_pair(-1,i)));
        }
        set <pair <int, pair <int,int> > > :: iterator it = s.begin();
        int prev=-1;
        while(it!=s.end())
        {
            set <pair <int, pair <int,int> > > :: iterator i = it;
            while(i!=s.end() && i->first == it->first)
            {
                int index = (i->second).second;
                int h = buildings[index][2];
                if((i->second).first==1)
                {
                    c.insert(make_pair(h, index));
                }
                else
                {
                    c.erase(c.lower_bound(make_pair(h, index)));
                }
                i++;
            }
            set <pair <int, int> > :: reverse_iterator last = c.rbegin();
            cout<<it->first<<" "<<(it->second).first<<" "<<(it->second).second<<endl;
            if(last == c.rend())
            {
                ans.push_back(make_pair(it->first, 0));
                prev=0;
                it=i;
                continue;
            }
            if(buildings[last->second][2] != prev)
            {
                ans.push_back(make_pair(it->first, last->first));
                prev=buildings[last->second][2];
            }
            it=i;
            
        }
        return ans;
    }
};