class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //KADANE's ALGORITHM
        //1. Iterate thru the array - keep maxSum=INT_MIN and currentSum = 0
        //2. Start adding, update maxSum but only keep sum if sum > 0, else discard
        //3. return ans at end. 

        int ans=0, currentSum = 0, maxSum = INT_MIN; 

        for(int i=0; i<nums.size(); i++){
            currentSum += nums[i]; 
            if(currentSum > maxSum) {
                 maxSum = currentSum; 
            } 

            if(currentSum < 0){
                currentSum = 0; 
            }
        }

        return maxSum; 
    }
};