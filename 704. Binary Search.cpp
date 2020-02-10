class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high = nums.size();
        while(low<high) {
            int mid = (high+low)/2;
            if(target>nums[mid])
                low = mid+1;
            else if (target<nums[mid])
                high = mid;
            else
                return mid;
        }
        
        return -1;
    }
};
