class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0, prev = 0, curr = 1; 

        for(int i=1; i<s.size(); i++){
            if(s[i-1] != s[i]){
                count += min(prev, curr); 
                prev = curr;
                curr = 1; 
            } else curr++; 
        }

        return count+=min(prev,curr); 
    }
};