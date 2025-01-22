class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 1, right = nums.size() - 2; 
        if(nums.size() == 1) return 0; 
        if(nums[0] > nums[1]) return nums[0]; 
        if(nums[nums.size() - 2] > nums[nums.size() - 1]) return 0; 

        while(left <= right){
            int mid = left + (right - left) / 2; 

            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid; 

            if(nums[mid] > nums[mid-1]) {
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }
        return -1; 
    }
};