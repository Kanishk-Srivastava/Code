class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1; 
        while(left <= right){
            int mid = left + (right - left) /2; 
            if(nums[mid] == target) return mid; 
            //check if left part is sorted? 
            if(nums[left] <= nums[mid]){
                //check if the target lies between this part 
                if(nums[left] <= target && target <= nums[mid]){
                    right = mid - 1; 
                } else left = mid + 1; 
            } else {
                if(target >= nums[mid] && target <= nums[right]){
                    left = mid + 1;
                } else right = mid - 1; 
            }
        }
        return -1; 
    }
};