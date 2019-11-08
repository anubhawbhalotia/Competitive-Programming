/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match(string &a, string &b)
    {
        int ans = 0;
        for(int i = 0; i != 6; i++)
        {
            if(a[i] == b[i])
                ans++;
        }
        return ans;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        srand(time(NULL));
        while(1)
        {
            vector <string> temp;
            string g = wordlist[rand() % wordlist.size()];
            int x = master.guess(g);
            if(x == 6)
                return ;
            for(string s : wordlist)
            {
                if(match(s, g) == x)
                {
                    temp.push_back(s);
                }
            }
            wordlist = temp;
        }   
    }
};