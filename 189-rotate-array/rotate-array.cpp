class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //1,2,3,4,5,6,7
        // after reverse 7,6,5,4,3,2,1 
        //reverse first k elementsk = 3 
        // 5,6,7,4,3,2,1
        //reverse remaining elements 
        // 5,6,7,1,2,3,4
        int n = nums.size(); 
        k %= n; 
        reverse(nums.begin(), nums.end()); 
        reverse(nums.begin(), nums.begin() + k); 
        reverse(nums.begin() + k, nums.end()); 
   
    }
};