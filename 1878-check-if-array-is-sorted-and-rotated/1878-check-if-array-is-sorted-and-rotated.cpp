class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(); 
        int count=0; 

        //check if there exist any point of rotation
        for(int i=1; i<n; i++){
            if(nums[i-1] > nums[i]){
                count++;
            }
        }

        //check for the last and first element (condition true then it is sorted)
        if(nums[n-1] > nums[0]){
            count++; 
        }

        return count<=1; 
    }
};