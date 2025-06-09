class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0; 
        unordered_map<int,int> prefixCount; 
        prefixCount[0] = 1;
        int count = 0; 
        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i]; 
            int target = prefixSum - k; 
            if(prefixCount.find(target) != prefixCount.end())
            {
                count += prefixCount[target];
            }
            prefixCount[prefixSum]++; 
        }
        return count; 
    }
};