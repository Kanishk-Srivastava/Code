class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); 
        unordered_map<int, bool> memo; 
        return dfs(0, s, dict, memo); 
    }

    bool dfs(int idx, string& s, unordered_set<string>& dict,   unordered_map<int, bool>& memo){
        if(idx == s.size()) return true; 
        if(memo.count(idx)) return memo[idx];

        for(int i = idx; i <= s.size(); i++){
            string prefix = s.substr(idx, i-idx+1); 
            if(dict.count(prefix) && dfs(i+1, s, dict, memo)){
                return memo[idx] = true; 
            }
        }

        return memo[idx] = false; 
    }
};