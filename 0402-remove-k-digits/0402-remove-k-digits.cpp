class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = ""; 

        for(int i=0; i<num.size(); i++){
            while(!result.empty() && k > 0 && result.back() > num[i]){
                result.pop_back(); 
                k--; 
            }

            if(!result.empty() || num[i] != '0'){
                result.push_back(num[i]); 
            }
        }

        while(!result.empty() && k > 0){
            result.pop_back(); 
            k--; 
        }

        if(result == "") return "0"; 

        return result; 
    }
};