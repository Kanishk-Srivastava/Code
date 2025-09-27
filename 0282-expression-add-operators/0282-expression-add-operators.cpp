class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result; 
        backtrack(num, target, 0, 0, 0, "", result);
        return result; 
    }

    void backtrack(string& num, long target, int idx, long total, long last, string expr, vector<string>& result){
        if(idx == num.size()){
            if(total == target){
                result.push_back(expr);
                return; 
            }
        }

        for(int i=idx; i<num.size(); i++){
            if(i>idx && num[idx] == '0') break; 

            string part = num.substr(idx, i - idx + 1); 
            long curr = stol(part); 

            if(idx == 0){
                backtrack(num, target, i+1, curr, curr, part, result);
            } else {
                backtrack(num, target, i+1, total + curr, curr, expr + "+" + part, result); 
                backtrack(num, target, i+1, total - curr, -curr, expr + "-" + part, result); 
                backtrack(num, target, i+1, total - last + last * curr , last* curr, expr + "*" + part, result); 
            }
        }
    }
};