class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //1. Find break point
        //2. Find the next bigger number vs the number at the break point
        //3. Swap the two numbers
        //4. Reverse the number from break point idx + 1 -> end. 

        int idx = -1; 

        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]) { 
                idx = i; 
                break; 
            }
        }
        if(idx == -1) {
            reverse(nums.begin(), nums.end()); 
            return; 
        }

        for(int i=nums.size()-1; i>idx; i--){
            if(nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break; 
            }
        }

        reverse(nums.begin() + idx + 1, nums.end()); 
    }
};