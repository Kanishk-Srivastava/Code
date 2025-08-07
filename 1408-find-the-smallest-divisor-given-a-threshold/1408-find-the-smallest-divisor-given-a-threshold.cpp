class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end()); 
        int ans = -1; 
        while(low <= high){
            int mid = low + (high - low) / 2; 
            if(possible(nums, threshold, mid)){
                ans = mid; 
                high = mid - 1; 
            } else low = mid + 1; 
        }
        return ans; 
    }

    bool possible(vector<int>& nums, int threshold, int mid){
        long long sum = 0; 
        for(int i=0; i<nums.size(); i++){
            sum +=ceil(nums[i] /(double) mid); 
        }
        return sum <= threshold; 
    }
};