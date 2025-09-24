class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path; 
        vector<vector<int>> ans;
        dfs(1, n, k, path, ans); 
        return ans; 
    }

    void dfs(int start, int remain, int k, vector<int>& path, vector<vector<int>>& ans){
        if(path.size() == k && remain == 0){
            ans.push_back(path);
            return; 
        }

        for(int i=start; i<=9; i++){
            if(i > remain) break; 
            int pick = i; 
            path.push_back(pick); 
            dfs(i+1, remain - pick, k, path, ans); 
            path.pop_back(); 
        }

    }
};