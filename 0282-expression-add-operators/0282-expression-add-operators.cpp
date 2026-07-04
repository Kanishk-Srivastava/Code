class Solution {
public:

    void solve(string num, int target, int idx, string expr, long long currVal, long long lastVal, vector<string>& ans){
        if(idx == num.size()){
            if(currVal == target){
                ans.push_back(expr);
            }
            return; 
        }

        for(int i=idx; i<num.size(); i++){
            if(i > idx && num[idx] == '0') break; 

            string part  = num.substr(idx, i-idx+1); 
            long long val = stoll(part); 

            if(idx == 0){
                solve(num, target, i+1, part, val, val, ans); 
            } else {
                // + 
                solve(num, target, i+1, expr + "+" + part, currVal + val, val, ans); 

                //-
                solve(num, target, i+1, expr + "-" + part, currVal - val, -val, ans); 

                //* 
                solve(num, target, i+1, expr + "*" + part, currVal - lastVal + (lastVal * val), lastVal * val, ans);
            }


        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans; 

        solve(num, target, 0, "", 0, 0, ans); 
        return ans;
    }
};