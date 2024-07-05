class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0; 
        int count2 = 0; 
        int element1 = INT_MIN; 
        int element2 = INT_MIN; 
        vector<int> ans; 
        for(int i=0; i<nums.size(); i++){
            if(count1 == 0 && element2 != nums[i]){
                element1 = nums[i]; 
                count1=1;
            } else if(count2 == 0 && element1 != nums[i]){
                element2 = nums[i]; 
                count2=1;
            } else if(nums[i] == element1){
                count1++; 
            } else if(nums[i] == element2){
                count2++; 
            } else {
                count1--; 
                count2--; 
            }
        }
        count1=0; 
        count2=0; 
        for(int i =0; i<nums.size(); i++){
            if(nums[i] == element1){
                count1++; 
            }
            if(nums[i] == element2){
                count2++; 
            }
        }
        int n = nums.size(); 
        int minimumOccurence = int(n/3) +1; 
        if(count1 >= minimumOccurence){
            ans.push_back(element1); 
        }
        if(count2 >= minimumOccurence){
            ans.push_back(element2); 
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         //using hashmap
//         vector<int> ans;
//         unordered_map<int,int> countMap; 

//         for(int i=0;i<nums.size(); i++){
//             countMap[nums[i]]++;
//         }

//         for(auto i : countMap){
//             if(i.second > (nums.size()/3)){
//                 ans.push_back(i.first);
//             }
//         }

//         return ans;
//     }
// };