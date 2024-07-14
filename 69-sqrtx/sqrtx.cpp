class Solution {
public:
    int mySqrt(int x) {
        long long left = 1, right = x, ans = 0; 
        if(x < 2){
            return x; 
        }

        while(left <= right){
            long long mid = left + (right - left)/2; 

            if(mid * mid > x){
                right = mid - 1; 
            } else {
                ans = mid; 
                left = mid + 1; 
            }
        }
        return (int) ans; 
        
    }
};