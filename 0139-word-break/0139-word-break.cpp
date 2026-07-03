class Solution {
public:

    bool solve(int idx, string& s, unordered_set<string>& st, vector<int>& dp){
        if(idx == s.size()) return true; 
        if(dp[idx] != -1) return dp[idx]; 
        for(int l=1; l<=s.size() - idx; l++){
            string temp = s.substr(idx, l); 
            if(st.find(temp) != st.end()){
                if(solve(idx + l, s, st, dp)){
                    return dp[idx] = 1; 
                }

            }
        }

        return dp[idx] = 0; 
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st; 
        vector<int> dp(s.size(), -1); 
        for(auto& word : wordDict){
            st.insert(word); 
        }
        return solve(0, s, st, dp); 

    }
};