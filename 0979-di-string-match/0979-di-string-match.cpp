class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans; 
        int i=0, j=s.size(); 
        for(char c : s ){
            ans.push_back(c == 'I' ? i++ : j--);
        }
        ans.push_back(j); 
        return ans; 
    }
};