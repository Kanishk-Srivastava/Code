class Solution {
public:
    int findMinNum(vector<int>& nums){
        int minNum = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            minNum = min(minNum, nums[i]);
        }
        return minNum; 
    }
    int findMaxNum(vector<int>& nums){
        int maxNum = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            maxNum = max(maxNum, nums[i]);
        }
        return maxNum; 
    }

    int calculateDivisor(vector<int>& nums, int threshold, int mid){
        int sum = 0; 
        int division = 1; 
        for(int i = 0; i<nums.size(); i++){
            division = ceil(nums[i]/(double) mid); 
            sum += division;  
        }
        //reverse condition as more the sum means less is the divisor hence bigger divisor required
        return sum <= threshold; 
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size() > threshold) return -1; 
        int left = 1;
        int right = findMaxNum(nums); 
        int ans=0; 
        while(left <= right){
            int mid = left + (right-left)/2; 
            if(calculateDivisor(nums,threshold, mid)){
                ans = mid; 
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        return ans; 
    }
};