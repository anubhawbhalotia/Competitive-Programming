class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        unordered_map <string, int> keyToIndex;
        vector<vector<int>> data;
        vector<int> timestampCounter;
        int x = 0;
    }
    
    void set(string key, string value, int timestamp) {
        if(keyToIndex.find(key) == keyToIndex.end())
        {
            keyToIndex[]
        }
    }
    
    string get(string key, int timestamp) {
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */