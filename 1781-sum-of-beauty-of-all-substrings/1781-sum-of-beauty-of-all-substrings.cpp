class Solution {
public:
    int beautySum(string s) {
        int ans = 0; 


        for(int i=0; i<s.size(); i++){
            vector<int> freq(26,0); 
            for(int j = i; j<s.size(); j++){
                freq[s[j] - 'a']++; 

                int minF = INT_MAX, maxF = INT_MIN; 

                for(auto f : freq){
                    if(f > 0){
                        minF = min(minF, f); 
                        maxF = max(maxF, f); 
                    }
                }
            ans += (maxF - minF); 
            }

        }

        return ans; 
    }
};