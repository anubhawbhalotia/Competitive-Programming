class LRUCache {
public:
    typedef struct node
    {
        struct node *next, *prev;
        int key, val;
        node(int k = -1, int d = -1)
        {
            key = k;
            val = d;
            prev = NULL;
            next = NULL;
        }
    }node;
    unordered_map <int, node*> data;
    int cap;
    node *head, *tail;
    LRUCache(int capacity) {
        head = new node(0, 0);
        tail = new node(0, capacity);
        head->next = tail;
        tail->prev = head;
    }
    node* remove_node(node* p)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        return p;
    }
    void add_node(node* p)
    {
        tail->prev->next = p;
        p->prev = tail->prev;
        p->next = tail;
        tail->prev = p;
    }
    int get(int key) {
        if(data.find(key) != data.end())
        {
            node* p = data[key];
            remove_node(p);
            add_node(p);
            return p->val;
        }
        return -1;
    }
    void put(int key, int value) {
        node *p = NULL;
        if(data.find(key) != data.end())
        {
            p = remove_node(data[key]);
            p->val = value;
        }
        else
        {
            if(head->val == tail->val)
            {
                data.erase(head->next->key);
                p = remove_node(head->next);
                p->key = key;
                p->val = value;
            }
            else
            {
                p = new node(key, value);
                head->val++;
            }
            data[key] = p;
        }
        add_node(p);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */