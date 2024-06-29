//-----------OPTIMAL SOLUTION -----> DUTCH NATIONAL FLAG ALGORITHM
//1. mid = 0, low = 0, high = size()-1
//2. 0 -> low -1 sorted 0s | low -> mid -1 sorted 1s | mid -> high unsorted (which is the given array and will reduce until all are sorted) | high + 1 -> size() - 2 sorted 2s. 
//3. If nums[mid] == 1 -> mid ++ | nums[mid] == 1 ->swap(nums[mid], nums(low)) -> low++ | nums[mid] == 2 -> swap(nums[mid], nums[high]) -> high --. 


class Solution { 
    public: 
        void sortColors(vector<int>& nums){
            int mid=0, low=0, high = nums.size()-1; 
            while(mid <= high){
                if(nums[mid] == 1){
                    mid++; 
                } else if(nums[mid] == 0){
                    swap(nums[mid], nums[low]); 
                    mid++;
                    low++; 
                } else if(nums[mid] == 2){
                    swap(nums[mid], nums[high]); 
                    high--; 
                }
            }
        }
};
// ---------- KIND OF A BRUTE FORCE SOLUTION -----------------
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int numZero=0, numOne=0, numTwo=0; 
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i] == 0){
//                 numZero++; 
//             } else if(nums[i] == 1){
//                 numOne++; 
//             } else if(nums[i] == 2){
//                 numTwo++; 
//             }
//         }
//     vector<int> ans; 
//         for(int a=0; a<numZero; a++){
//             ans.push_back(0);
//         }
//         for(int b=0; b<numOne; b++){
//             ans.push_back(1);
//         }
//          for(int c=0; c<numTwo; c++){
//             ans.push_back(2);
//         }
//     nums = ans; 
//     }
// };