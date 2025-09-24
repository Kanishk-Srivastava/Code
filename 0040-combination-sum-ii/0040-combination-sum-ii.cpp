class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> ans;
        dfs(0, target, candidates, path, ans);
        return ans;
    }

    void dfs(int start, int remain, vector<int>& candidates, vector<int>& path,
             vector<vector<int>>& ans) {
        if (remain == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i-1] == candidates[i]) continue; 
            int pick = candidates[i];
            if(pick > remain) return; 
            path.push_back(pick);
            dfs(i + 1, remain - pick, candidates, path, ans);
            path.pop_back();
        }
    }
};