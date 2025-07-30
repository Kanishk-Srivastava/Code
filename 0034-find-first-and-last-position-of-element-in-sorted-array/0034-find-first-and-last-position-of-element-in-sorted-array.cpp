class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums,target); 
        int last = findLast(nums,target); 
        return {first, last}; 
    }

    int findFirst(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1; 
        int result = -1; 
        while(low <= high){
            int mid = low + (high - low) / 2; 

            if(target < nums[mid]){
                high = mid - 1; 
            } else if(target > nums[mid]){
                low = mid + 1; 
            } else {
                result = mid; 
                high = mid - 1; 
            }
        }
        return result; 
    }

    int findLast(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1; 
        int result = -1; 
        while(low <= high){
            int mid = low + (high - low) / 2; 
            if(target < nums[mid]){
                high = mid - 1; 
            } else if(target > nums[mid]){
                low = mid + 1; 
            } else {
                result = mid; 
                low = mid + 1; 
            }
        }
        return result; 
    }
    
};