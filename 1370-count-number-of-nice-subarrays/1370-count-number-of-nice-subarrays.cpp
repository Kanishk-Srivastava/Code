class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int result = 0;
        int prevCount = 0;
        int oddCount = 0;
        int n = nums.size();
        int i = 0, j = 0; 
        while (j < n) {
            if (nums[j] % 2 != 0) { // if j encounters an odd number
                oddCount++;
                prevCount =
                    0; // reset prevCount to 0 as new odd number is encountered
            }

            while (oddCount == k) {
                prevCount++; //found 1 valid subarray
                if (i < n && nums[i] % 2 != 0) {
                    oddCount--; // as odd number is removed from behind
                }
                i++; 
            }
            result += prevCount; 
            j++; 
        }
        return result; 
    }
};