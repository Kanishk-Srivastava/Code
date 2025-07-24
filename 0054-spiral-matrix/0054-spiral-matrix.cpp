class Solution {
public:
    vector<int> result;

    void spiralHelper(vector<vector<int>>& matrix, int top, int bottom,
                      int left, int right) {
        // Base case if bounds are invalid
        if (top > bottom || left > right)
            return;

        // Top row
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;

        // Right column
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;

        // Bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }

        spiralHelper(matrix, top, bottom, left, right);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        spiralHelper(matrix, 0, n - 1, 0, m - 1);
        return result;
    }
};
