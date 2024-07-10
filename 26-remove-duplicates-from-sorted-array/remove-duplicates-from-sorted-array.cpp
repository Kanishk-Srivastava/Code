class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //1,1,2,3,3,4,5
        //i
        //j
        int i=0, j=0; 
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != nums[j]){
                nums[j+1] = nums[i]; 
                j++; 
            }
        }
        return j+1; 
    }
};