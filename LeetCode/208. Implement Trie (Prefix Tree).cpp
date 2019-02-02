class Trie {
public:
    /** Initialize your data structure here. */
    typedef struct node {
        struct node *a[26];
        bool complete;
        node()
        {
            for(int i=0;i<26;i++)
                a[i]=NULL;
            complete=false;
        }
    }node;
    node *head;
    Trie() {
        head=new node();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        node *p =head;
        int index=0;
        while(index!=word.length())
        {
            if(p->a[word[index]-97] == NULL)
                p->a[word[index]-97] = new node;
            p=p->a[word[index]-97];
            index++;
        }
        p->complete=true;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* p=head;
        int index=0;
        while(index!=word.size())
        {
            if(p->a[word[index]-97] == NULL)
                return false;
            p=p->a[word[index]-97];
            index++;
        }
        return p->complete;
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* p=head;
        int index=0;
        while(index!=prefix.size())
        {
            if(p->a[prefix[index]-97] == NULL)
                return false;
            p=p->a[prefix[index]-97];
            index++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */