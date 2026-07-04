class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; 
        int n = nums.size();
        int subsets = 1 << n; 

        for(int j=0; j<subsets; j++){
            vector<int> temp; 
            for(int i=0; i<n; i++){
                if(j & (1 << i)){
                    temp.push_back(nums[i]); 
                }
            }
            result.push_back(temp);
        }

        return result; 
    }
};