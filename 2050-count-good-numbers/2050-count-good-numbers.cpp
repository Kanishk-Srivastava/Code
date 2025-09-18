class Solution {
public:
    const long long MOD = 1e9+7; 
    int countGoodNumbers(long long n) {
        long long even = (n+1) / 2; 
        long long odd = n/2; 

        return (power(5, even) * power(4, odd)) % MOD; 
    }

    long long power(int a, long long b){
        if(b == 0) return 1; 
        long long half = power(a, b/2); 
        long long result = (half * half) % MOD; 
        if(b%2 == 1){
            result = (result*a) % MOD; 
        }
        return result; 
    }
};