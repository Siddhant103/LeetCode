class MyHashMap {
    vector<vector<pair<int,int>>> map;
    const int size =  10000;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        map.resize(size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key%size;
        vector<pair<int, int>> &row = map[index];
        for(auto itr=row.begin(); itr!=row.end();itr++){
            if(itr->first == key){
                itr->second = value;
                return;
            }
        }
        row.push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key%size;
        vector<pair<int,int>> &row = map[index];
        for(auto itr=row.begin();itr!=row.end();itr++){
            if(itr->first == key){
                return itr->second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key%size;
        vector<pair<int,int>> &row = map[index];
        for(auto itr=row.begin();itr!=row.end();itr++){
            if(itr->first == key){
                row.erase(itr);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */