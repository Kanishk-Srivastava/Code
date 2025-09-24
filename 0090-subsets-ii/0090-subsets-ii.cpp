class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<int> path;
        vector<vector<int>> ans;
        dfs(0, nums, path, ans);
        return ans;
    }

    void dfs(int start, vector<int>& nums, vector<int>& path,
             vector<vector<int>>& ans) {
        ans.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            dfs(i + 1, nums, path, ans);
            path.pop_back();
        }
    }
};