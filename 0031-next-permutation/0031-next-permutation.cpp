class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivotIdx = -1;
        int swapIdx = -1;
        int n = nums.size();
        // find pivot index
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivotIdx = i;
                break;
            }
        }


        if (pivotIdx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 1 5 4 3 2 -> 2 5 4 3 1
        // find swap index
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[pivotIdx]) {
                swapIdx = i;
                break;
            }
        }
        swap(nums[pivotIdx], nums[swapIdx]);
        reverse(nums.begin() + pivotIdx + 1, nums.end());
    }
};