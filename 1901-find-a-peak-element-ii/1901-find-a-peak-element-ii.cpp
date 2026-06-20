class Solution {
public:

    int findMaxIndex(vector<vector<int>>& mat, int midCol){
        int ans = -1; 
        int index = -1; 
        for(int i=0; i<mat.size(); i++){
            if(mat[i][midCol] > ans){
                ans = mat[i][midCol]; 
                index = i; 
            }
        }
        return index; 
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(); 
        int m = mat[0].size(); 

        int low = 0, high = m -1; 

        while(low <= high){
            int midCol = low + (high - low) / 2; 

            int maxRowIndex = findMaxIndex(mat, midCol); 

            int left = midCol - 1 >= 0 ? mat[maxRowIndex][midCol-1] : -1; 
            int right = midCol + 1 < m ? mat[maxRowIndex][midCol+1] : -1; 

            if(mat[maxRowIndex][midCol] > left && mat[maxRowIndex][midCol] > right){
                return {maxRowIndex, midCol};
            } else if(mat[maxRowIndex][midCol] > right){
                high = midCol - 1; 
            } else low = midCol + 1; 
            
        }

        return {-1,-1}; 
    }
};