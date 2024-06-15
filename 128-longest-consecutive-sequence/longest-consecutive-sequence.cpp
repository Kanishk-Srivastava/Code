class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    unordered_set<int> num_set; 
    for (int i = 0; i < nums.size(); i++) {
        num_set.insert(nums[i]);
    }
    //1,1,101,2,3,4,102,103
    //1,101,2,3,4,102,103

   
    int longest_sub = 1; 

    for(auto i : num_set){
        if(num_set.find(i - 1) == num_set.end()){
            int curr_long = 1; 
            int x = i ;
            while(num_set.find(x + 1) != num_set.end()){
                curr_long = curr_long + 1; 
                x = x+1; 
            }
            longest_sub = max(longest_sub, curr_long);
        }
    }
    return longest_sub;
    }
};



//OPTIMAL SOLUTION NLOGN
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         //1,1,2,3,4,100,101,102

//         if (nums.empty()) return 0;

//         // Sort the array
//         sort(nums.begin(), nums.end());

//         int curr_long = 1; // Initialize current sequence length to 1
//         int longest_sub = 1; // Initialize longest sequence length to 1

//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] != nums[i - 1]) { // Check if current number is not a duplicate
//                 if (nums[i] == nums[i - 1] + 1) {
//                     // Increment current sequence length if consecutive
//                     curr_long++;
//                 } else {
//                     // Update longest sequence length
//                     longest_sub = max(longest_sub, curr_long);
//                     // Reset current sequence length
//                     curr_long = 1;
//                 }
//             }
//         }

//         // Final check to update the longest sequence length
//         longest_sub = max(longest_sub, curr_long);

//         return longest_sub;
//     }
// };
