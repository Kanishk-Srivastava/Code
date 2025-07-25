class Solution {
public:
    vector<vector<int>> twoSum(int target, vector<int>& nums, int j, int k){
        vector<vector<int>> result; 
        while(j < k){
            if(nums[j] + nums[k] > target) k--; 
            else if(nums[j] + nums[k] < target) j++; 
            else {
                result.push_back({-target, nums[j], nums[k]}); 
                j++; 
                k--; 
                while(j < k && nums[j] == nums[j-1]) j++; 
                while(j < k && nums[k] == nums[k+1]) k--; 
            }
        }
        return result; 
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result; 
        if(nums.size() < 3) return {}; 

        sort(nums.begin(), nums.end()); 

        for(int i=0; i<nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; 
            int target = -nums[i]; 
            vector<vector<int>>pairs = twoSum(target, nums, i+1, nums.size() - 1); 
            result.insert(result.end(), pairs.begin(), pairs.end()); 
        }
        return result; 
    }
};