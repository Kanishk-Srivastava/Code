class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowHasZero = false, firstColHasZero = false; 

        //check if first row has 0
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0] == 0) firstRowHasZero = true; 
        }

        //check if first col has 0
        for(int i=0; i<matrix[0].size(); i++){
            if(matrix[0][i] == 0) firstColHasZero = true; 
        }

        //use 1st row & col as markers and traverse internal matrix
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0; 
                    matrix[i][0] = 0; 
                }
            }
        }

        //fill the marked row col as 0
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0; 
                }
            }
        }

        //now if firstRow or firstCol has zero then fill them to 0
        for(int i=0; i<matrix.size(); i++){
           if(firstRowHasZero) matrix[i][0] = 0; 
        }
        for(int i=0; i<matrix[0].size(); i++){
           if(firstColHasZero) matrix[0][i] = 0; 
        }

    }
};