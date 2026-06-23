class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int target, int j, int k) {
        vector<vector<int>> triplet;
        while (j < k) {
            if (nums[j] + nums[k] > target)
                k--;
            else if (nums[j] + nums[k] < target)
                j++;
            else {
                int val = -target;
                triplet.push_back({val, nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
        return triplet;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {}; 
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = -nums[i];

            vector<vector<int>> triplet =
                twoSum(nums, target, i + 1, nums.size() - 1);
            result.insert(result.end(), triplet.begin(), triplet.end());
        }
        return result;
    }
};