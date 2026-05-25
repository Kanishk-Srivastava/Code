class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0, currentDepth = 0; 

        for(char c : s){
            if(c == '('){
                currentDepth++; 
                maxDepth = max(currentDepth, maxDepth); 
            } else if ( c == ')'){
                currentDepth--; 
            }
        }

        return maxDepth; 
    }
};