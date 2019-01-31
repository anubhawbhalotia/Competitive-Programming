class LRUCache {
public:
    int a[10000]={};
    int c[100000]={};
    int d[10000]={};
    int cap;
    int pt=1;
    int ptmin=1;
    int start=0,  end=0;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(a[key]==0)
            return -1;
        else
        {
            c[d[key]]=0;
            d[key]=pt;
            c[pt]=key;
            pt++;
            while(c[ptmin]==0)
            {
                ptmin++;
            }
            return a[key];
        }
    }
    
    void put(int key, int value) {
       if(a[key]!=0)
       {
           a[key]=value;
           c[d[key]]=0;
           d[key]=pt;
           c[pt]=key;
           pt++;
           return;
       }
        if(end-start>=cap)
        {
            while(c[ptmin]==0)
            {
                ptmin++;
            }
            d[c[ptmin]]=0;
            a[c[ptmin]]=0;
            c[ptmin]=0;
            
            start++;
            end++;
        }
        else
        {
            end++;
        }
        a[key]=value;
        c[pt]=key;
        d[key]=pt;
        pt++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */