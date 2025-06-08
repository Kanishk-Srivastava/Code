class Solution {
public:
    vector<int> result;

    void spiralHelper(vector<vector<int>>& matrix, int top, int bottom, int left, int right) {
        // Base case: if bounds are invalid
        if (top > bottom || left > right) return;

        // Top row
        for (int j = left; j <= right; j++)
            result.push_back(matrix[top][j]);
        top++;

        // Right column
        for (int i = top; i <= bottom; i++)
            result.push_back(matrix[i][right]);
        right--;

        // Bottom row (if any)
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                result.push_back(matrix[bottom][j]);
            bottom--;
        }

        // Left column (if any)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result.push_back(matrix[i][left]);
            left++;
        }

        // Recurse on the inner submatrix
        spiralHelper(matrix, top, bottom, left, right);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        spiralHelper(matrix, 0, n - 1, 0, m - 1);
        return result;
    }
};
