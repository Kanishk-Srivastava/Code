class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x; 
        long long low = 0, high = x; 

        while(low <= high){
            long long mid = low + (high - low) / 2; 

            long long val = mid * mid; 


            if(val <= x){
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }

        return (int) high; 
    }
};