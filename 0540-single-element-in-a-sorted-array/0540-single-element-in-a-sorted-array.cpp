class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 2; 
        if(nums.size() == 1) return nums[0]; 
        if(nums[0] != nums[1]) return nums[0]; 
        if(nums[nums.size() - 1] != nums[nums.size() - 2]) return nums[nums.size() - 1]; 
        int ans; 
        while(left <= right){
            int mid = left + (right - left) / 2; 
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
                ans = nums[mid];
            }
            if(mid%2 == 0){
                if(nums[mid] == nums[mid+1]){
                    left = mid + 1;
                } else {
                    right = mid - 1; 
                }
            } else {
                if(nums[mid] == nums[mid-1]){
                    left = mid + 1; 
                } else {
                    right = mid - 1; 
                }
            }
        }
        return ans;
    }
};