class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int limit = strs[0].size(); 

        for (auto &s : strs){
            limit = min(limit, (int)s.size()); 
        }

        for(int i=0; i<limit; i++){
            char ch = strs[0][i]; 
            for(int j=1; j<strs.size(); j++){
                if(strs[j][i] != ch) return strs[0].substr(0, i); 
            }
        }

        return strs[0].substr(0, limit); 
    }
};