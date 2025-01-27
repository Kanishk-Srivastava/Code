class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        if (nums.size() < k) {
            return -1;
        }

        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int number = findSums(nums, mid);

            if (number <= k) {
                right = mid - 1;
            } else
                left = mid + 1;
        }
        return left;
    }

    int findSums(vector<int>& nums, int mid) {
        int sum = 0;
        int count = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + sum <= mid) {
                sum += nums[i];
            } else {
                sum = nums[i];
                count++;
            }
        }
        return count;
    }
};