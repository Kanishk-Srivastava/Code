class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1;
        int n = nums.size();

        while (i < n && j < n) {
            // Find an incorrect even index (nums[i] should be even)
            while (i < n && nums[i] % 2 == 0) i += 2;
            // Find an incorrect odd index (nums[j] should be odd)
            while (j < n && nums[j] % 2 == 1) j += 2;
            
            // Swap if both are within bounds
            if (i < n && j < n) {
                swap(nums[i], nums[j]);
            }
        }
        return nums; 
    }
};