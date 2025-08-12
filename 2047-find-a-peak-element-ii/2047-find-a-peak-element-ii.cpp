class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n=mat[0].size(); 
        int low = 0, high = n-1; 

        while(low <= high){
            int mid = low + (high - low) / 2; 

            int maxRow = 0; 

            for(int i=1; i<m; i++){
                if(mat[i][mid] > mat[maxRow][mid])
                    maxRow = i;
            }

            int curr = mat[maxRow][mid]; 
            int left = (mid - 1 >=0 ) ? mat[maxRow][mid-1] : INT_MIN; 
            int right = (mid + 1 < n) ? mat[maxRow][mid+1] : INT_MIN; 

            if(curr > left && curr > right){
                return {maxRow, mid}; 
            } else if(right > curr)
                low = mid + 1; 
            else high = mid - 1; 
        }

        return {-1, -1};
    }
};