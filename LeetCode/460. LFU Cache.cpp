class LFUCache {
public:
    int a[3301];
    list <int> l[3301];
    int size;
    int lf;
    int capacity;
    pair <int, list <int> :: iterator> b[3301]; //first = frequency, second = iteraor in l list
    LFUCache(int capacity) {
        for(int i = 0; i!= 3300; i++)
            a[i] = -1;
        lf = 0;
        size = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(a[key] == -1)
            return -1;
        l[b[key].first].erase(b[key].second);
        b[key].first++;
        l[b[key].first].push_back(key);
        b[key].second = l[b[key].first].end();
        b[key].second--;
        return a[key];
    }
    
    void put(int key, int value) {
        if(capacity == 0)
            return ;
        if(a[key] != -1)
        {
            a[key] = value;
            l[b[key].first].erase(b[key].second);
            b[key].first++;
            l[b[key].first].push_back(key);
            b[key].second = l[b[key].first].end();
            b[key].second--;
        }
        else
        {
            if(size == capacity)
            {
                while(l[lf].empty())
                   lf++;
                a[(unsigned int)(l[lf].front())] = -1;
                l[lf].pop_front();
                size--;
            }
           
            size++;
            a[key] = value;
            b[key].first = 1;
            l[1].push_back(key);
            b[key].second = l[1].end();
            b[key].second--;
            lf = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */