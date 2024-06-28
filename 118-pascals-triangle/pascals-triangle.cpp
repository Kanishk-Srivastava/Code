class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans; 
        vector<int> firstRow = {1}; 
        ans.push_back(firstRow); 

        if(numRows == 1) return ans; //edge case 

        for(int i=1; i<numRows; i++){
            vector<int> currentRow; 
            vector<int> prevRow = ans[i-1]; 
            currentRow.push_back(1); 
            for(int j=0; j<i-1; j++){
                int element = prevRow[j] + prevRow[j+1]; 
                currentRow.push_back(element); 
            }
            currentRow.push_back(1); 
            ans.push_back(currentRow); 
        }
    return ans; 
    }
};