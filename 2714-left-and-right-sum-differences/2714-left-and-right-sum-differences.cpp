class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightPrefixSum(n, 0), leftPrefixSum(n, 0), ans(n, 0);

        for (int i = 1; i < n; i++) {
            leftPrefixSum[i] = (nums[i - 1] + leftPrefixSum[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            rightPrefixSum[i] = (nums[i + 1] + rightPrefixSum[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            ans[i] = abs(leftPrefixSum[i] - rightPrefixSum[i]);
        }

        return ans;
    }
};