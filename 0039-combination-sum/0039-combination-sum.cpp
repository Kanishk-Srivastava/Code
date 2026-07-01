class Solution {
public:

    void solve(int index,vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans, int target ){
        if(index == candidates.size()){
            if(target == 0){
            ans.push_back(temp); 
            }
            return; 
        }

        if(candidates[index] <= target){
            temp.push_back(candidates[index]);
            solve(index, candidates, temp, ans, target - candidates[index]);
            temp.pop_back(); 
        }

        solve(index+1, candidates, temp, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int> temp; 

        solve(0, candidates, temp, ans, target); 
        return ans; 
    }
};