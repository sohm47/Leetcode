class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> cache;
        for(int i=0; i<arr.size(); i++)
            cache[arr[i]] += 1;
        
        int count = 0;
        for(auto &i: cache) {
            if(cache.find(i.first+1) != cache.end())
                count += cache[i.first];
        }
        
        return count;
    }
};
