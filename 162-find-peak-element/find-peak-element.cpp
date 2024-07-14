class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans=0, left = 1, right = nums.size() - 2;

        if(nums.size() == 1){
            return 0; 
        }
        if(nums[0] > nums[1]){
            return 0; 
        }
        if(nums[nums.size() - 1] > nums[nums.size() - 2]){
            return nums.size() - 1; 
        }

        while(left <= right){
            int mid = left + (right - left)/2; 

            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
                return mid; //this is the peak 
            } else if(nums[mid] > nums[mid - 1]){
                //peak exists in the right part
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }            
        }
        return -1;
        
    }
};