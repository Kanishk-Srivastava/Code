class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore's voting algorithm 
        int currentElement = 0; 
        int occurence = 0; 
        int count = 0; 

        for(int i=0; i<nums.size(); i++){
            if(count == 0){
                currentElement = nums[i]; 
                count++;
            }else if(nums[i] == currentElement){
                count++; 
            } else {
                count--; 
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == currentElement){
                occurence++; 
            }
        }
        if(occurence > (nums.size()/ 2)){
            return currentElement;
        } else return -1;
    }
};