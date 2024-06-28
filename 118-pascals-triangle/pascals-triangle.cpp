//using nCr formula
class Solution {
public:
    vector<int> generateRow(int row){
        long long ans = 1; 
        vector<int> currentRow; 
        currentRow.push_back(1); 
        for(int col=1; col<row; col++){
            ans = ans * (row-col); 
            ans = ans / col; 
            currentRow.push_back(ans); 
        }
        return currentRow; 
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans; 
        for(int i=1; i<=numRows; i++){
           ans.push_back(generateRow(i));
        }        
    return ans; 
    }
};
//Brute force
// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> ans; 
//         vector<int> firstRow = {1}; 
//         ans.push_back(firstRow); 

//         if(numRows == 1) return ans; //edge case 

//         for(int i=1; i<numRows; i++){
//             vector<int> currentRow; 
//             vector<int> prevRow = ans[i-1]; 
//             currentRow.push_back(1); 
//             for(int j=0; j<i-1; j++){
//                 int element = prevRow[j] + prevRow[j+1]; 
//                 currentRow.push_back(element); 
//             }
//             currentRow.push_back(1); 
//             ans.push_back(currentRow); 
//         }
//     return ans; 
//     }
// };