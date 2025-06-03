class Solution {
    public int majorityElement(int[] nums) {
        int count=0; 
        int element=0; 
        int occurence = 0; 
        for (int i=0 ; i< nums.length; i++){
            if(count == 0){
                element = nums[i]; 
                count++; 
            } else if(nums[i] == element) {
                count++; 
            } else {
                count--;
            }
        }
        for(int i=0; i<nums.length; i++){
            if(element == nums[i]){
                occurence++;
            }
            if(occurence>nums.length/2){
                return element;
            }
        }
        return -1;
    }
}