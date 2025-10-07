class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = ""; 
        int n = num.size(); 

        for(int i = 0; i<n; i++){
            while(result.length() > 0 && k > 0 && result.back() > num[i]){
                result.pop_back(); 
                k--; 
            }
            if(result.length() > 0 || num[i] != '0'){
                result.push_back(num[i]); 
            }
        }
        
        while(k>0 && !result.empty()){
            result.pop_back(); 
            k--; 
        }

        if(result == "") return "0";

        return result; 

    }
};