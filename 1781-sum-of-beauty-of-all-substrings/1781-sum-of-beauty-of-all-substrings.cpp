class Solution {
public:
    int beautySum(string s) {
        int ans = 0; 

        for(int i=0; i<s.size(); i++){
            vector<int> freq(26,0); 

            for(int j=i; j<s.size(); j++){
                freq[s[j] - 'a']++; //freq of each char counter array
                int maxF = INT_MIN, minF = INT_MAX; 

                for(auto f : freq){
                    if(f > 0){
                        maxF = max(maxF, f); 
                        minF = min(minF, f); 
                    }
                }

                ans += (maxF - minF); 
            }
        }

        return ans; 
    }
};