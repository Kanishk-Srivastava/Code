class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0; 
        vector<int> mp(3,0); 
        int result = 0; 
        int n = s.length(); 

        while(j < n){
            char ch = s[j]; 
            mp[ch - 'a']++; //inc freq of that char idx in mp

            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0){
                result += (n - j); 

                mp[s[i] - 'a']--; //as we re inc i; 
                i++; 
            }
            j++; 
        }

        return result; 
    }
};