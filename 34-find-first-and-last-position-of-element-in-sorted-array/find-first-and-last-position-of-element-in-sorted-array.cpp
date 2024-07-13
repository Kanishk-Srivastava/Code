class Solution {
public:
    int leftIdx(vector<int>& nums, int target){
        int left = 0, right = nums.size() -1; 
        int idx = -1; 
        while(left<=right){
            int mid = left + (right-left)/2; 
            if(nums[mid] == target){
                idx = mid; 
                right = mid - 1; 
            } else if(nums[mid] < target){
                left = mid + 1; 
            } else { 
                right = mid - 1; 
            }
        }
        return idx; 
    }

    int rightIdx(vector<int>& nums, int target){
        int left = 0, right = nums.size() -1; 
        int idx = -1; 
        while(left<=right){
            int mid = left + (right-left)/2; 

            if(nums[mid] == target){
                idx = mid; 
                left = mid + 1; 
            } else if(nums[mid] < target){
                left = mid + 1; 
            } else { 
                right = mid - 1; 
            }
        }
        return idx; 
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = leftIdx(nums,target); 
        int end = rightIdx(nums,target); 
        return {start,end};
    }
};