class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size(), 0);

        int p = 0, n = 1; 

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0){
                result[p] = nums[i]; 
                p+=2; 
            } else if(nums[i] < 0){
                result[n] = nums[i]; 
                n+=2; 
            }
        }
        return result; 
    }
};