class FirstUnique {
    list<int> unique;
    unordered_map<int, list<int>::iterator> cache;
    unordered_set<int> duplicates;
public:
    FirstUnique(vector<int>& nums) {
        for(int &num: nums)
            add(num);
    }
    
    // Time: O(1)
    int showFirstUnique() {
        if(unique.size() == 0)
            return -1;
        return unique.front();
    }
    
    // Time: O(1)
    void add(int value) {
        bool found = false;
        if(cache.find(value) != cache.end())
            found = true;
        if(!found && duplicates.find(value) == duplicates.end()) {
            unique.push_back(value);
            cache[value] = prev(unique.end());
        }
        else {
            if(found) {
                unique.erase(cache[value]);
                cache.erase(value);
                duplicates.insert(value);
            }
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
