class Solution {
public:
    vector<int> ans; 
    void spiralHelper(vector<vector<int>>& matrix, int top, int bottom, int left, int right){

        if(top > bottom || left > right){
            return; 
        }

        for(int i=left; i<=right; i++){
            ans.push_back(matrix[top][i]); 
        }
        top++; 

        for(int i=top; i<=bottom; i++){
            ans.push_back(matrix[i][right]); 
        }
        right--;
        if(top<=bottom){
            for(int i=right; i>=left; i--){
                ans.push_back(matrix[bottom][i]); 
            }
            bottom--; 
        }

        if(left<=right){
            for(int i=bottom; i>=top; i--){
                ans.push_back(matrix[i][left]); 
            }
            left++;
        }

        spiralHelper(matrix, top, bottom, left, right);

    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size(); 

        spiralHelper(matrix, 0, n-1, 0, m-1); 
        return ans; 
    }
};