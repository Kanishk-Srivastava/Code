class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1, candidate2; 
        int count1 = 0, count2 = 0; 
        vector<int> result; 
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == candidate1) count1++; 
            else if(nums[i] == candidate2) count2++; 
            else if(count1 == 0) {
                candidate1 = nums[i]; 
                count1++;
            } else if(count2 == 0){
                candidate2 = nums[i]; 
                count2++; 
            } else {
                count1--; 
                count2--; 
            }
        }

        int freq1=0, freq2 = 0; 

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == candidate1) freq1++; 
            if(nums[i] == candidate2) freq2++; 
        }

        if(freq1 > floor(nums.size()/3)) result.push_back(candidate1); 
        if(freq2 > floor(nums.size()/3)) result.push_back(candidate2);
        return result;  
    }
};