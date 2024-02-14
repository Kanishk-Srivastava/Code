class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        prefixSum.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            prefixSum.push_back(prefixSum[i-1]+nums[i]); //populate prefixSum array
        }
    }
    
    int sumRange(int left, int right) {
        //1,2,3,4,5
        //1,3,6,10,15
        //1-4 --> prefixSum at 4 = 15 prefixSum at (1 index previous to 1) = 1 --> 15-1 = 14
        if(left == 0){
            return prefixSum[right];
        }
        return prefixSum[right] - prefixSum[left-1];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */