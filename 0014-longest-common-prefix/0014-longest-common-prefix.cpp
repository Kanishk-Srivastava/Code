class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";

        int limit = strs[0].size(); //first word length

        for(auto &s : strs){
            limit = min((int)s.size(), limit); //find min length amongst words
        }

        for(int i=0; i<limit; i++){ //iterate each character column wise
            char ch = strs[0][i]; //char from 1st column

            for(int j=1; j<strs.size(); j++){ //check each char now in row
                if(strs[j][i] != ch) return strs[0].substr(0, i); //return the string until chars matched
            }
        }
        return strs[0].substr(0, limit); //return the string as entire part untill limit is matching 
    }
};