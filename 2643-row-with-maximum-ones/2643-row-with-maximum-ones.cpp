class Solution {
public:

    int findFirst(vector<int> arr){
        int low = 0, high = arr.size() - 1; 
        int ans = arr.size(); 
        while(low <= high){
            int mid = low + (high - low) / 2; 

            if(arr[mid] >= 1){
                ans = mid ;
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return arr.size() - ans; 
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int index = 0; 
        int maxCount = 0;
        for(int i=0; i<mat.size(); i++){
            sort(mat[i].begin(), mat[i].end()); 
            int count = findFirst(mat[i]); 
            if(count > maxCount){
                maxCount = count; 
                index = i; 
            } 
        }
        return {index, maxCount};
    }
};