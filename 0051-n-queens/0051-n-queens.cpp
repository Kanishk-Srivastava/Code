class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> diags;
    unordered_set<int> antidiags;
    // bool isValid(vector<string>& board, int row, int col, int n){
    //     // check upper rows

    //     for(int i=row-1; i>= 0; i--){
    //         if(board[i][col] == 'Q') return false;
    //     }

    //     // check left upper diag

    //     for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
    //         if(board[i][j] == 'Q') return false;
    //     }

    //     // check right upper diag
    //     for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
    //         if(board[i][j] == 'Q') return false;
    //     }

    //     return true;
    // }

    void solve(vector<string>& board, int n, int row,
               vector<vector<string>>& result) {
        if (row >= n) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            int diagVal = row + col;
            int antidiagVal = row - col;

            if (cols.find(col) != cols.end() ||
                diags.find(diagVal) != diags.end() ||
                antidiags.find(antidiagVal) != antidiags.end()) {
                continue;
            }
            cols.insert(col);
            diags.insert(diagVal);
            antidiags.insert(antidiagVal);
            board[row][col] = 'Q';
            solve(board, n, row + 1, result);
            board[row][col] = '.';
            cols.erase(col);
            diags.erase(diagVal);
            antidiags.erase(antidiagVal);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        solve(board, n, 0, result);
        return result;
    }
};