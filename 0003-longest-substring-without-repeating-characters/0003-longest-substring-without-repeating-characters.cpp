class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp; 
        int maxLen = 0; 

        int l = 0; 

        for(int r = 0; r<s.size(); r++){
            char c = s[r]; 

            if(mpp.find(c) != mpp.end() && mpp[c] >= l){
                l = mpp[c] + 1; 
            }

            mpp[c] = r; 
            maxLen = max(maxLen, r - l + 1); 
        }
        return maxLen; 
    }
};