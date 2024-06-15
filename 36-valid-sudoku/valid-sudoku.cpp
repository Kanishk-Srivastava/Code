class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen; 
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char current_val = board[i][j]; 
                if(current_val != '.'){
                    if(!seen.insert(string(1, current_val) + "found in row " + to_string(i)).second ||
                    !seen.insert(string(1, current_val) + "found in column " + to_string(j)).second || 
                    !seen.insert(string(1, current_val)  + "found in subgrid " + to_string(i/3) + "-" + to_string(j/3)).second) return false;



                }
            }
        }
        return true; 
    }
};