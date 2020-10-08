class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<set<int>> cache;
    MyHashSet() {
        cache.resize(1000);
    }
    
    void add(int key) {
        cache[getHashKey(key)].insert(key);
    }
    
    void remove(int key) {
        cache[getHashKey(key)].erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashKey = getHashKey(key);
        return cache[hashKey].find(key) != cache[hashKey].end();        
    }
    
    int getHashKey(int num) {
        return num%1000;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
