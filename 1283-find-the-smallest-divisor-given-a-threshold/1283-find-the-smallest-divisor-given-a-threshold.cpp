class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1; 
        int high = *max_element(nums.begin(), nums.end()); 
        int divisor = -1; 
        while(low <= high){
            int mid = low + (high - low) /2; 

            if(calculateSum(nums,mid) <= threshold){
                divisor = mid; 
                high = mid - 1; 
            } else low = mid + 1;
        }
        return divisor;       
    }

    int calculateSum(vector<int>& nums, int mid){
        int sum = 0; 
        for(int i=0; i<nums.size(); i++){
            int result = (ceil((double)nums[i] / mid)); 
            sum +=result; 
        }
        return sum; 
    }
};