class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int left = 0, right = 0, countZero = 0, result = 0; 
        int windowSum = 0; 
        while(right < nums.size()){
            windowSum += nums[right]; 

            while(left < right && (nums[left] == 0 || windowSum > goal)){
                if(nums[left] == 0){
                    countZero++; 
                } else countZero = 0; 
                windowSum -= nums[left]; 
                left++; 
            }

            if(windowSum == goal){
                result += 1 + countZero; 
            }
            right++; 
        }

        return result; 

    }
};