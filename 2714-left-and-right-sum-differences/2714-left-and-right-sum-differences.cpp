class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftSum = 0, rightSum = 0; 
        vector<int> ans; 
        for(int i=0; i<nums.size(); i++){
            rightSum += nums[i]; 
        }

        for(int i =0; i<nums.size(); i++){
            int val = nums[i]; 

            rightSum -= val; 
            ans.push_back(abs(leftSum - rightSum)); 

            leftSum += val; 
        }
        return ans; 
    }
};