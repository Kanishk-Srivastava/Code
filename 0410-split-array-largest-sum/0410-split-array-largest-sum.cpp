class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()); 
        int high = accumulate(nums.begin(), nums.end(), 0); 
        int ans = -1; 
        while(low <= high){
            int mid = low + (high - low) / 2; 
            int sum = 0; 
            int splitCount = 1; 
            for(int i=0; i<nums.size(); i++){
                if(sum + nums[i] > mid){
                    splitCount++; 
                    sum = 0; 
                }
                sum += nums[i]; 
            }

            if(splitCount <= k){
                ans = mid; 
                high = mid - 1;
            } else 
                low = mid + 1; 
        }
        return ans; 
    }
};