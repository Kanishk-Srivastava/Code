class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1; 
        if(nums.size() == 1) return 0; 

        while(low <= high){
            int mid = low + (high - low) / 2; 

            if((mid == 0 || nums[mid-1] < nums[mid]) && (mid == nums.size() - 1 || nums[mid] > nums[mid+1])){
                return mid; 
            } else if(mid < nums.size() - 1 && nums[mid+1] > nums[mid]) {
                low = mid + 1; 
            } else high = mid - 1; 
        }
    return -1; 
    }
};