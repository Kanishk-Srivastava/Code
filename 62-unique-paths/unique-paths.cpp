class Solution {
public:
    int uniquePaths(int m, int n) {
        //solved using combinatorics
        //nCr formula here n = total number of steps we can take that is m-1 + n-1 = m+n-2
        //r here is either m-1 or n-1 because i can either go m-1 right moves or n-1 down moves.
        int N = m+n-2; 
        int r = m-1; 
        long long res = 1; 
        for(int i=1; i<=r; i++){
            res = res * (N-r+i)/i; 
        }
        return (int) res; 
    }
};