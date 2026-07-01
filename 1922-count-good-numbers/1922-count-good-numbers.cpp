class Solution {
public:
    long long mod = 1e9 + 7;
    long long power(int n, long long x){
        if(x == 0) return 1; 

        long long half = power(n, x/2); 
        
        long long ans = (half * half) % mod; 
        if(x % 2 == 1){
            ans = ( n * ans ) % mod;
        }
        return ans; 
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1) / 2; 
        long long odd = n/2; 

        long long ans =  (power(5,even) * power(4,odd) ) % mod;

        return ans; 
    }

};