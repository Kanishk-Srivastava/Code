class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int x = nums.size(); 
        
        for(int i=1; i<x; i++)
            nums[i] += nums[i-1] ; 
        return nums ; 
    }
};