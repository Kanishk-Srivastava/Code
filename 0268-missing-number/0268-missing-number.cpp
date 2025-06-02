class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); 
        int numSum = accumulate(nums.begin(), nums.end(), 0); 
        int sizeSum = (n*(n+1))/2; 
        return sizeSum - numSum; 
    }
};