class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum = INT_MAX;
        int ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    j++;
                } else
                    k--;

                int diff = abs(sum - target);
                if (diff < closestSum) {
                    ans = sum;
                    closestSum = diff;
                }
            }
        }
        return ans;
    }
};