class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1; 

        while(left <= right){
            int mid = left + (right - left)/2; 
            if(nums[mid] == target){
                return mid;
            }
            //check if the left part is sorted
            if(nums[left] <= nums[mid]){
               //check if the target lies between this sorted part 
               if(target>= nums[left] && target <= nums[mid]){
                    right = mid - 1; //do binary search on this part
               } else {
                    left = mid + 1; //discard this part of the array as target doesnt lie here
               }
            } else { //left is not sorted, right is sorted
                if(target >= nums[mid] && target <= nums[right]){
                    left = mid + 1; 
                } else {
                    right = mid - 1; 
                }
            }
        }
        return -1; 
    }
};