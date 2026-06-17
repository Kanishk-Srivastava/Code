class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()); 
        int high = accumulate(nums.begin(), nums.end(), 0); 

        while(low<=high){
            int mid = low + (high - low) / 2; 

            if(canSplit(mid, nums, k)){
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }

        return low; 
    }

    bool canSplit(int mid, vector<int>nums, int k){
        int splitCount = 1; 
        int sum = 0; 

        for(int i = 0; i<nums.size(); i++){
            if(sum + nums[i] <= mid){
                sum += nums[i]; 
            } else {
                splitCount++; 
                sum = nums[i]; 
            }
        }

        return splitCount <= k; 
    }
};