class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0; 
        unordered_map<int,int> prefixCount; 
        prefixCount[0] = 1; //at 0, we have 1 sub array which sums to 0 
        int count = 0; 

        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i]; 
            int target = prefixSum - k; 

            if(prefixCount.count(target)){
                count += prefixCount[target]; 
            }

            prefixCount[prefixSum]++; 
        }
        return count; 
    }
};