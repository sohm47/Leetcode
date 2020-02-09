class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> arr;
    unordered_map<int, int> m;
    
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) == m.end()) {
            arr.push_back(val);
            m[val] = arr.size()-1;
            return true;
        }
        
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) != m.end()) {
            m[arr.back()] = m[val];
            swap(arr[m[val]], arr[arr.size()-1]);
            arr.pop_back();
            m.erase(val);
            return true;
        }
        
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
