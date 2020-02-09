class NumArray {
public:
    vector<int> array;
    NumArray(vector<int>& nums) {
        if(nums.size()!=0) {
            array = nums;
            array[0] = nums[0];
            for(int i=1; i<nums.size(); i++)
                array[i] += array[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        if(i!=0)
            return array[j]-array[i-1];
        else 
            return array[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
