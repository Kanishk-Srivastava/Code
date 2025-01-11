class Solution {
public:
    int findFirst(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1; 
        int idx=-1; 
        while(left <= right){
            int mid = left + (right - left) / 2; 
            if(nums[mid] == target){
                idx = mid; 
                right = mid -1; 
            } else if(nums[mid] > target){
                right = mid -1; 
            } else left = mid + 1; 
        }
        return idx;
    }

    int findLast(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1; 
        int idx=-1; 
        while(left <= right){
            int mid = left + (right - left) / 2; 
            if(nums[mid] == target){
                idx = mid; 
                left = mid + 1; 
            } else if(nums[mid] > target){
                right = mid -1; 
            } else left = mid + 1; 
        }
        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int firstIdx = findFirst(nums, target); 
        int lastIdx = findLast(nums,target); 
        return {firstIdx, lastIdx}; 
    }
};