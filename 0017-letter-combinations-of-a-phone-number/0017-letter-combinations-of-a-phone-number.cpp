class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {}; 
        vector<string> ans; 
        string path = "";

        unordered_map<char, string> mp; 
        mp['2'] = "abc"; 
        mp['3'] = "def"; 
        mp['4'] = "ghi"; 
        mp['5'] = "jkl"; 
        mp['6'] = "mno"; 
        mp['7'] = "pqrs"; 
        mp['8'] = "tuv"; 
        mp['9'] = "wxzy"; 
    
        dfs(0, digits, path, ans, mp);
        return ans; 
    }

    void dfs(int idx, string& digits, string& path, vector<string>& ans,unordered_map<char, string>& mp){
        if(idx >= digits.length()){
            ans.push_back(path); 
            return; 
        }

        char ch = digits[idx]; 
        string temp = mp[ch]; 

        for(int i = 0; i<temp.length(); i++){
            path.push_back(temp[i]); 
            dfs(idx+1, digits, path, ans, mp);
            path.pop_back(); 
        }
    }
};