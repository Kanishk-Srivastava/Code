//BIT MANIPULATION
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; 
        int n = nums.size(); 

        for(int mask = 0; mask < (1 << n); mask++){
            vector<int> subset; 
            for(int i=0; i < n; i++){
               if(mask & (1 << i)){
                subset.push_back(nums[i]); 
               }     
            }
            result.push_back(subset); 
        }
        return result; 
    }
};

/* RECURSION
class Solution {
public:
    vector<vector<int>> result; 

    void solve(int i, vector<int>& nums, vector<int>& temp){
        if(i >=nums.size()){
            result.push_back(temp); 
            return; 
        }
        temp.push_back(nums[i]);
        solve(i+1, nums, temp); 
        temp.pop_back(); 
        solve(i+1, nums, temp); 
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp; 

        solve(0, nums, temp); 

        return result; 
    }
};
*/ 