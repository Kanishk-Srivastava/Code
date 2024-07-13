class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, maxLen = 0; 
        int currLen = 0; 
        unordered_map<char,int> charMap; 
        int n = s.size(); 

        while(r<n){
         if(charMap.find(s[r]) != charMap.end() && charMap[s[r]] >= l) { //char present in map
                l = charMap[s[r]] + 1; 
            }
            charMap[s[r]] = r; 
            currLen = r - l + 1;
            r++;
            maxLen = max(currLen, maxLen);
        }
        return maxLen;        
    }
};