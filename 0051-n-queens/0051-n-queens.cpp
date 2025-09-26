class Solution {
public:
    int N;
    vector<vector<string>> result;
    unordered_set<int> cols;
    unordered_set<int> diags;
    unordered_set<int> antiDiags;

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.'));

        solve(board, 0);

        return result;
    }

    void solve(vector<string>& board, int row) {
        if (row >= N) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < N; col++) {
            int diagConst = row + col;
            int antiConst = row - col;

            if (cols.find(col) != cols.end() ||
                diags.find(diagConst) != diags.end() ||
                antiDiags.find(antiConst) != antiDiags.end()) {
                continue;
            }

            cols.insert(col);
            diags.insert(diagConst);
            antiDiags.insert(antiConst);
            board[row][col] = 'Q';
            solve(board, row + 1);
            cols.erase(col);
            diags.erase(diagConst);
            antiDiags.erase(antiConst);
            board[row][col] = '.';
        }
    }
};