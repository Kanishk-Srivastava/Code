class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowHasZero = false;
        bool firstColHasZero = false;

        // Check if first column has zero
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                firstColHasZero = true;
            }
        }

        // Check if first row has zero
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) {
                firstRowHasZero = true;
            }
        }

        // Traverse internal rows cols 
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Apply zeroes based on markers
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Final row and column zeroing
        if (firstRowHasZero) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }

        if (firstColHasZero) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
