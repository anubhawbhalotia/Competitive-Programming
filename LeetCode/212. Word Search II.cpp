class Solution {
public:
    typedef struct node 
    {
        struct node* a[26];
        bool com;
        bool got;
        node() {
            for(int i=0;i<26;i++)
                a[i]=NULL;
            com=false;    
            got=0;
        }
    }node;
    void insert(string word) {
        node *p=head;
        int index=0;
        while(index!=word.size()) {
            if(p->a[word[index]-97] == NULL)
                p->a[word[index]-97] = new node();
            p = p->a[word[index]-97];
            index++;
        }
        p->com = true;
    }
    node* head;
    int n,m;
    vector <string> v;
    int row[4] = {1,0,-1,0}, col[4] = {0,1,0,-1};
    vector < vector < int > > f;
    void findWord(int r,  int c, vector<vector<char>>& word, node* l, string temp)
    {
        string h = temp + word[r][c];
        if(l->a[word[r][c] - 97] == NULL)
            return;
        l = l->a[word[r][c] - 97];
        if(l->com==true & l->got==false) {
            v.push_back(h);
            l->got=true;
        }
        f[r][c]=1;
        for(int k=0;k<4;k++) {
            int R=r+row[k], C=c+col[k];
            if(R <0 || R >=n || C <0 || C>=m)
                continue;
            if(f[R][C]==1)
                continue;
            findWord(R,C,word,l, h);    
        }
        f[r][c]=0;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        head = new node();
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++) {
            vector < int> y;
            for(int j=0;j<m;j++)
                y.push_back(0);
            f.push_back(y);
        }
        for(int i=0; i<words.size(); i++)
            insert(words[i]);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++)
                findWord(i,j, board, head, "");  
        }
        return v;            
    }
};
