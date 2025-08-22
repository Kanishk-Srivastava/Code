class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq; 

        for(char c : s) freq[c]++; 

        int n = s.size(); 
        vector<vector<char>> bucket(n+1); 

        for(auto &p : freq){
            bucket[p.second].push_back(p.first); 
        }
        
        string result; 

        for(int i=n; i>0; i--){
            for(char c : bucket[i]){
                result.append(i,c); 
            }
        }
        return result;
    }
};