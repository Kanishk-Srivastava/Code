class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //edge cases 
        if(nums.size() == 1){
            return nums[0]; //only 1 element exists in the array
        }
        if(nums[0] != nums[1]){
            return nums[0]; //first element in single element
        }
        if(nums[nums.size() - 1] != nums[nums.size() - 2]){
            return nums[nums.size() - 1]; //last element in the single element
        }

        int ans=0, left = 1, right = nums.size() - 2; 

        while(left <= right){
            int mid = left + (right - left)/2; 

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid]; //single element as sorted and one sibling must be equal 
            }
            //check if mid is even or odd
            if(mid % 2 == 0 && nums[mid-1] == nums[mid] || mid % 2 == 1 && nums[mid] == nums[mid+1]){
                //element exists in the left half 
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
    return -1;         
    }
};