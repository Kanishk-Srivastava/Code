class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {}; 
        vector<string> ans; 
        string temp = "";

        unordered_map<char, string> mp; 
        mp['2'] = "abc"; 
        mp['3'] = "def"; 
        mp['4'] = "ghi"; 
        mp['5'] = "jkl"; 
        mp['6'] = "mno"; 
        mp['7'] = "pqrs"; 
        mp['8'] = "tuv"; 
        mp['9'] = "wxzy"; 
    
        solve(0, digits, temp, ans, mp);
        return ans; 
    }

    void solve(int idx, string& digits, string& temp, vector<string>& ans,unordered_map<char, string>& mp){
        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }

        char digit = digits[idx];
        string mapping = mp[digit]; 

        for(int i=0; i<mapping.length(); i++){
            temp.push_back(mapping[i]); 
            solve(idx+1, digits, temp, ans, mp); 
            temp.pop_back();
        } 
    }
};