class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0; 
        int minLen = INT_MAX; 
        int count = 0; 
        int m = s.size(); 
        int n = t.size(); 
        int sIdx = -1; 
        unordered_map<char, int> mp; 
        for(int i=0; i<n; i++){
            mp[t[i]]++; 
        }
        while(r < m){
            mp[s[r]]--; 
            if(mp[s[r]] >= 0){
                count++; 
            }
            while(count == n){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1; 
                    sIdx = l; 
                }
                mp[s[l]]++; 
                if(mp[s[l]] > 0) count--; 
                l++; 
            }
            r++; 
        }
        return sIdx == - 1 ? "" : s.substr(sIdx, minLen); 
    }
};