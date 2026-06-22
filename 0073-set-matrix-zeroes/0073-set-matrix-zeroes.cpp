class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstColHasZero = false, firstRowHasZero = false;

        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0)
                firstColHasZero = true;
        }

        for (int i = 0; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0)
                firstRowHasZero = true;
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            if (firstColHasZero)
                matrix[i][0] = 0;
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            if (firstRowHasZero)
                matrix[0][i] = 0;
        }
    }
};